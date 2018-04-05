//---------------------------------------------------------------------------
//		E L E N A   P r o j e c t:  ELENA Compiler
//               
//		This file contains ELENA Engine Derivation Tree classes
//
//                                              (C)2005-2018, by Alexei Rakov
//---------------------------------------------------------------------------

#ifndef derivationH
#define derivationH 1

#include "syntax.h"
#include "compilerscope.h"

#define EXPRESSION_IMPLICIT_MODE   1
//#define EXPRESSION_MESSAGE_MODE    2
//#define EXPRESSION_OPERATOR_MODE   4
//#define EXPRESSION_OBJECT_REQUIRED 8

namespace _ELENA_
{

// --- DerivationWriter ---

class DerivationWriter : public _DerivationWriter
{
   SyntaxWriter _writer;

   void writeNode(Symbol symbol);

public:
   void begin();
   void close();
   void beginModule(ident_t filePath);
   void closeModule();

   virtual void writeSymbol(Symbol symbol);
   virtual void writeTerminal(TerminalInfo& terminal);

   DerivationWriter(SyntaxTree& target)
      : _writer(target)
   {
   }
};

// --- DerivationWriter ---

class DerivationTransformer //: public _DerivationTransformer
{
   // --- TemplateScope ---
   struct DerivationScope
   {
//      enum Type
//      {
//         ttNone           = 0,
////         ttFieldTemplate  = 1,
////         ttMethodTemplate = 2,
////         ttCodeTemplate   = 3,
////         ttExtTemplate    = 4
//      };
//
//      Type         type;
//      ref_t        templateRef;  // NOTE : should be zero for template declaration
//      ref_t        reference;
//      ForwardMap   parameters;
////      ForwardMap   fields;
//      SubjectMap   parameterValues;
////
////      SNode        exprNode;     // used for code template
////      SNode        codeNode;
////      SNode        elseNode;
////      SNode        nestedNode;
////      SNode        identNode;
//
//      SyntaxTree* autogeneratedTree;

      CompilerScope*   compilerScope;
//      DerivationScope* parent;
      MessageMap*      attributes;
//      IdentifierList* imports;

//      int              mode;
//      ref_t            extensionTemplateRef;

      IdentifierString ns;
      ident_t          sourcePath;

      ref_t mapAttribute(SNode terminal/*, int& paramIndex*/);
//      ref_t mapAttribute(SNode terminal)
//      {
//         int dummy = 0;
//         return mapAttribute(terminal, dummy);
//      }
//
//      ref_t mapIdentifier(ident_t identifier);

      void raiseError(const char* message, SNode terminal)
      {
         compilerScope->raiseError(message, sourcePath, terminal);
      }
      void raiseWarning(int level, const char* message, SNode terminal)
      {
         compilerScope->raiseWarning(level, message, sourcePath, terminal);
      }

//      bool isTypeAttribute(SNode terminal);
//      bool isAttribute(SNode terminal);
//      bool isImplicitAttribute(SNode terminal);
//      bool isSubject(SNode terminal)
//      {
//         return !(isTypeAttribute(terminal) || isAttribute(terminal));
//      }

//      void loadParameters(SNode node);
//      void loadFields(SNode node);

      void copyName(SyntaxWriter& writer, SNode terminal);
//      void copyMessageName(SyntaxWriter& writer, SNode terminal);
////      void copyMessage(SyntaxWriter& writer, SNode terminal);
////      void copyIdentifier(SyntaxWriter& writer, SNode terminal);
//
//      ref_t mapNewReference(ident_t identifier);
//
      ref_t mapNewIdentifier(ident_t name, bool privateOne);
//      int mapParameter(ident_t identifier);
////      ref_t mapAttributeType(SNode terminal/*, bool& arrayMode, bool& paramMode*/);
////
////      ref_t mapTemplate(SNode terminal, int paramCounter = 0, int prefixCounter = 0);
////      ref_t mapClassTemplate(SNode terminal);
////      ref_t mapTerminal(SNode terminal, bool existing = false);
////      ref_t mapTypeTerminal(SNode terminal, bool existing = false);  // map type or reference
////      int mapIdentifier(SNode terminal);
////
////      ref_t mapTypeTemplate(SNode current);
//
//      bool generateClassName();
//
//      _Memory* loadTemplateTree();
//
      static ident_t resolvePathAndNs(ident_t fullName, IdentifierString& ns)
      {
         int comma_index = fullName.find(',');
         if (comma_index != NOTFOUND_POS) {
            ns.copy(fullName, comma_index);
            return fullName + comma_index + 1;
         }
         else return fullName;
      }

//      DerivationScope(DerivationScope* parent, ref_t attrRef)
//      {
//         this->compilerScope = parent->compilerScope;
//         this->attributes = parent->attributes;
//         this->imports = parent->imports;
//         this->autogeneratedTree = parent->autogeneratedTree;
//         //         this->parent = parent;
//
//         type = Type::ttNone;
//         templateRef = attrRef;
//         reference = 0;
//         sourcePath = NULL;
//         //mode = 0;
//         //extensionTemplateRef = 0;
//      }
      DerivationScope(CompilerScope* compilerScope, ident_t sourcePath, MessageMap* attributes/*, IdentifierList* imports*/)
      {
         this->sourcePath = resolvePathAndNs(sourcePath, this->ns);

         this->compilerScope = compilerScope;
         this->attributes = attributes;
//         this->imports = imports;
////         this->parent = NULL;
//
//         type = Type::ttNone;
////         templateRef = 0;
//         reference = 0;
//         autogeneratedTree = NULL;
////         mode = 0;
////         extensionTemplateRef = 0;
      }
   };

//   enum DeclarationAttr
//   {
//      daNone        = 0x0000,
////      daType        = 0x0001,
//      daClass       = 0x0002,
//      daTemplate    = 0x0004,
////      daField       = 0x0008,
////      daLoop        = 0x0020,
////      daImport      = 0x0040,
////      daExtern      = 0x0080,
////      daAccessor    = 0x0100,
////      daDblAccessor = 0x0300,
////      daCodeMask    = 0xF800,
////      daCode        = 0x0800,
////      daBlock       = 0x1800,
////      daDblBlock    = 0x3800,
////      daNestedBlock = 0x4800,
////      daExtension   = 0x8000
//   };

   SNode       _root;
//   MessageMap  _verbs;                            // list of verbs
//
//   bool compareAttributes(SNode node, DerivationScope& scope);

//   void loadParameterValues(SNode node, DerivationScope& scope/*, MessageMap* parentParameterValues, bool classMode = false*/);
//
//   void copyIdentifier(SyntaxWriter& writer, SNode terminal);
//   void copyParamAttribute(SyntaxWriter& writer, SNode current, DerivationScope& scope);
//   void copyFieldTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
////   void copyFieldInitTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
//   void copyExpressionTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
//   void copyTreeNode(SyntaxWriter& writer, SNode node, DerivationScope& scope);
//   void copyMethodTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
////   void copyTemplateTree(SyntaxWriter& writer, SNode node, DerivationScope& scope, SNode attributeValues, SubjectMap* parentAttributes, int mode = 0);
////   void copyTemplateAttributeTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
////   void copyOperator(SyntaxWriter& writer, SNode& node, DerivationScope& scope);
////
////   void autoGenerateExtensions(DerivationScope& scope, ref_t attrRef, SNode node);
//   ref_t generateNewTemplate(DerivationScope& scope, ref_t attrRef, SNode node);
//
//   bool generateTemplate(SyntaxWriter& writer, DerivationScope& scope, bool declaringClass, int mode = 0);
//
////   ref_t generateTemplate(SNode current, DerivationScope& scope, SubjectMap* parentAttributes);
////
////   ref_t mapAttributeType(SNode attr, DerivationScope& scope);
   ref_t mapAttribute(SNode terminal, DerivationScope& scope/*, bool& templateParam*/);

//   ref_t mapNewTemplate(SNode node, DerivationScope& scope/*, bool& arrayMode, int& paramIndex*/, bool templateMode, List<int>* templateAttributes);

   void recognizeScopeMembers(SNode& node, DerivationScope& scope, int mode);

//   bool isImplicitAttribute(SNode node, DerivationScope& scope);
//
//   bool checkVariableDeclaration(SNode node, DerivationScope& scope);
////   bool checkPatternDeclaration(SNode node, DerivationScope& scope);
////   bool checkArrayDeclaration(SNode node, DerivationScope& scope);
////
////   void generateMessage(SyntaxWriter& writer, SNode node, DerivationScope& scope, bool templateMode);
//   void generateTypeAttribute(SyntaxWriter& writer, SNode node, DerivationScope& scope/*, bool templateMode*/);
//
////   void generateSwitchTree(SyntaxWriter& writer, SNode current, DerivationScope& scope);
////   bool generateTemplateCode(SyntaxWriter& writer, DerivationScope& scope, SubjectMap* parentAttributes);
////   void generateCodeTemplateTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
//   void generateVariableTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
////   void generateArrayVariableTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
     void generateMessageTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
////   void generateClosureTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
   void generateCodeTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
//////   bool generateFieldTemplateTree(SyntaxWriter& writer, SNode node, DerivationScope& scope, SNode attributes, SyntaxTree& buffer, bool templateMode = false);
   void generateMethodTree(SyntaxWriter& writer, SNode node, DerivationScope& scope/*, bool templateMode = false*/);
   bool generateFieldTree(SyntaxWriter& writer, SNode node, DerivationScope& scope, SyntaxTree& buffer/*, bool templateMode = false*/); // returns true if in-place init found
//////   void generateCodeExpression(SyntaxWriter& writer, SNode node, DerivationScope& scope);
   void generateObjectTree(SyntaxWriter& writer, SNode node, DerivationScope& scope, int mode = 0);
   void generateExpressionTree(SyntaxWriter& writer, SNode node, DerivationScope& scope, int mode = 0);
////   void generateAssignmentOperator(SyntaxWriter& writer, SNode node, DerivationScope& scope);
//   void generateTemplateParameters(SNode node, DerivationScope& scope, bool templateMode);
////   void generateSubTemplate(SNode& node, DerivationScope& scope, bool templateMode);
//   void generateNewTemplate(SyntaxWriter& writer, SNode& node, DerivationScope& scope, bool templateMode);
   void generateAttributes(SyntaxWriter& writer, SNode node, DerivationScope& scope, bool rootMode/*, bool templateMode*/);
   void generateSymbolTree(SyntaxWriter& writer, SNode node, DerivationScope& scope);
   void generateClassTree(SyntaxWriter& writer, SNode node, DerivationScope& scope/*, SNode attributes,int nested = 0*/);
//   void generateTemplateScope(SyntaxWriter& writer, SNode node, DerivationScope& scope);

   void recognizeRootAttributes(SNode node, DerivationScope& scope);

   bool recognizeMethodScope(SNode node, DerivationScope& scope);
////   bool generateSingletonScope(SyntaxWriter& writer, SNode node, DerivationScope& scope, SNode attributes);
   bool recognizeDeclaration(SNode node/*, DerivationScope& scope*/);
//   void generateTemplateTree(SyntaxWriter& writer, SNode node, DerivationScope& scope/*, SNode attributes*/);
//   void generateAttributeTemplate(SyntaxWriter& writer, SNode node, DerivationScope& scope/*, bool templateMode, int mode = 0*/);
//
////   void generateSyntaxTree(SyntaxWriter& writer, SNode node, CompilerScope& scope, SyntaxTree& autogenerated, 
////      MessageMap* attributes, IdentidierList* imports, ident_t sourcePath);
////   void generateScope(SyntaxWriter& writer, SNode node, DerivationScope& scope/*, SNode attributes*/, int mode);

   void loadAttributes(CompilerScope& scope, ident_t name, MessageMap* attributes);

   void declareAttribute(SNode node, DerivationScope& scope);
////   bool declareType(SyntaxWriter& writer, SNode member, DerivationScope& scope, SNode attributes);
////   void includeModule(SNode ns, _CompilerScope& scope);

//   void saveTemplate(SNode node, DerivationScope& scope, DerivationScope::Type type, SyntaxTree& autogenerated, ref_t templateRef);

//   bool isVerbAttribute(SNode terminal);

   void recognizeRootScope(SNode node, DerivationScope& scope/*, int mode*/);

   void generate(SyntaxWriter& writer, SNode node, CompilerScope& scope, ident_t sourcePath, MessageMap* attributes/*,
      IdentifierList* imports, SyntaxTree& autogenerated*/);
   void recognize(CompilerScope& scope, SNode node, ident_t sourcePath, MessageMap* attributes);

public:
   void recognize(CompilerScope& scope, MessageMap* attributes);
   void generate(SyntaxWriter& writer, CompilerScope& scope, MessageMap* attributes);

   DerivationTransformer(SyntaxTree& tree);
};

} // _ELENA_

#endif // derivationH
