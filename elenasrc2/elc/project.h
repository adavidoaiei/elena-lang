//---------------------------------------------------------------------------
//		E L E N A   P r o j e c t:  ELENA Compiler
//
//		This header contains the declaration of the base class implementing
//      ELENA Project interface.
//                                              (C)2005-2014, by Alexei Rakov
//---------------------------------------------------------------------------

#ifndef projectH
#define projectH 1

#include "libman.h"

namespace _ELENA_
{

// --- Project list types ---
typedef String<wchar16_t, IDENTIFIER_LEN>      ProjectParam;
typedef Dictionary2D<int, const wchar16_t*>    ProjectSettings;
typedef Map<const tchar_t*, tchar_t*>          Sources;

typedef Map<const tchar_t*, tchar_t*> :: Iterator                                                               SourceIterator;
typedef _Iterator<ProjectSettings::VItem, _MapItem<const wchar16_t*, ProjectSettings::VItem>, const wchar16_t*> ForwardIterator;

// --- ELENA Project options ---
enum ProjectSetting
{
   opNone                  = 0x0000,

   // compiler options
   opAppPath		         = 0x0001,
   opProjectPath           = 0x0002,
   opLibPath               = 0x0003,
   opNamespace             = 0x0004,
   opTarget                = 0x0006,
   opOutputPath            = 0x0008,
   opEntry                 = 0x0009,
   opDebugMode             = 0x000A,
   opTemplate              = 0x000C,
   opEmbeddedSymbolMode    = 0x000D,
   opThreadMax             = 0x0013,

   // linker options
   opImageBase             = 0x0020,
   opSectionAlignment      = 0x0021,
   opFileAlignment         = 0x0022,
   opGCMGSize              = 0x0024,
   opGCObjectSize          = 0x0025,
   opSizeOfStackReserv     = 0x0026,
   opSizeOfStackCommit     = 0x0027,
   opSizeOfHeapReserv      = 0x0028,
   opSizeOfHeapCommit      = 0x0029,
   opPlatform              = 0x002A,      // defines the project platform type
   opGCYGSize              = 0x002B,

   // compiler engine options
   opWarnOnUnresolved      = 0x0041,
   opWarnOnWeakUnresolved  = 0x0042,
//   opWarnOnSignature       = 0x0043,

   // compiler optimization options
   opL0                    = 0x0050,   // generic

   opPrimitives            = 0x0060,
   opForwards              = 0x0061,
   opSources               = 0x0062,
   opTemplates             = 0x0063,
   opModuleForwards        = 0x0067
};

// --- ModuleInfo ---
struct ModuleInfo
{
   _Module* codeModule;
   _Module* debugModule;

   ModuleInfo()
   {
      codeModule = debugModule = NULL;
   }

   ModuleInfo(_Module* codeModule, _Module* debugModule)
   {
      this->codeModule =
      this->debugModule = NULL;
   }
};

// --- Project ---

class Project
{
protected:
   bool            _hasWarning;
   int             _numberOfWarnings;

   LibraryManager  _loader;
   ProjectSettings _settings;
   Sources         _sources;

   virtual ConfigCategoryIterator getCategory(_ConfigFile& config, ProjectSetting setting) = 0;
   virtual const char* getOption(_ConfigFile& config, ProjectSetting setting) = 0;

   bool loadOption(_ConfigFile& config, ProjectSetting setting);
   void loadIntOption(_ConfigFile& config, ProjectSetting setting);
   void loadIntOption(_ConfigFile& config, ProjectSetting setting, int minValue, int maxValue);
   void loadHexOption(_ConfigFile& config, ProjectSetting setting);
   void loadAlignedIntOption(_ConfigFile& config, ProjectSetting setting, int alignment);
   void loadBoolOption(_ConfigFile& config, ProjectSetting setting);
   bool loadPathOption(_ConfigFile& config, ProjectSetting setting, const tchar_t* path);

   void loadCategory(_ConfigFile& config, ProjectSetting setting, const tchar_t* configPath);
   void loadSourceCategory(_ConfigFile& config, const tchar_t* configPath);
   void loadPrimitiveCategory(_ConfigFile& config, const tchar_t* configPath);
   void loadForwardCategory(_ConfigFile& config);

public:
   virtual int getDefaultEncoding() = 0;

   // project
   virtual int IntSetting(ProjectSetting key, int defaultValue = 0)
   {
      return _settings.get(key, defaultValue);
   }

   virtual const wchar16_t* StrSetting(ProjectSetting key)
   {
      return _settings.get(key, DEFAULT_STR);
   }

   virtual bool BoolSetting(ProjectSetting key)
   {
      return (_settings.get(key, 0) != 0);
   }

////   virtual bool testSetting(ProjectSetting key)
////   {
////      return _settings.exist(key);
////   }

   SourceIterator getSourceIt()
   {
      return _sources.start();
   }

   ForwardIterator getForwardIt()
   {
      return _settings.getIt(opForwards);
   }

   virtual void printInfo(const char* msg, const char* value) = 0;
   virtual void printInfo(const char* msg, const wchar16_t* value) = 0;

//   virtual void raiseError(const char* msg) = 0;
   virtual void raiseError(const char* msg, const tchar_t* path, int row, int column, const wchar16_t* terminal = NULL) = 0;
   virtual void raiseError(const char* msg, const char* value) = 0;
   virtual void raiseError(const char* msg, const wchar16_t* value) = 0;
   virtual void raiseErrorIf(bool throwExecption, const char* msg, const tchar_t* path) = 0;

   virtual void raiseWarning(const char* msg, const tchar_t* path, int row, int column, const wchar16_t* terminal = NULL) = 0;
   virtual void raiseWarning(const char* msg, const tchar_t* path) = 0;

////   virtual void loadForward(const wchar16_t* forward, const wchar16_t* reference);
   virtual void loadConfig(_ConfigFile& config, const tchar_t* configPath);

   virtual void initLoader()
   {
      // if library path is set we need to set the loader root as well
      if (!emptystr(StrSetting(opLibPath)))
         _loader.setRootPath(Path(StrSetting(opLibPath)));

      // if package is set we need to set the loader package as well
      Path outputPath(StrSetting(opProjectPath), StrSetting(opOutputPath));

      _loader.setPackage(StrSetting(opNamespace), outputPath);
   }

   virtual const wchar16_t* resolveForward(const wchar16_t* forward);
   virtual const wchar16_t* resolveForward(const char* forward)
   {
      return resolveForward(ConstantIdentifier(forward));
   }

   // loader
   virtual _Module* loadModule(const wchar16_t* package, bool silentMode);

   virtual _Module* loadModule(const char* package, bool silentMode)
   {
      IdentifierString name(package);

      return loadModule(name, silentMode);
   }

   virtual _Module* resolveModule(const wchar16_t* referenceName, ref_t& reference, bool silentMode = false);
   virtual _Module* resolveCore(ref_t reference, bool silentMode = false);

   bool HasWarnings() const { return _hasWarning; }

   virtual int getTabSize() { return 4; }

   bool indicateWarning()
   {
      _hasWarning = true;

      if (_numberOfWarnings > 0) {
         _numberOfWarnings--;
         return true;
      }
      else return false;
   }

   virtual _Module* createModule(const tchar_t* sourcePath);
   virtual _Module* createDebugModule(const wchar16_t* name);

   virtual void saveModule(_Module* module, const tchar_t* extension);

   Project();
   virtual ~Project() {}
};

} // _ELENA_

#endif // projectH
