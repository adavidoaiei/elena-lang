/// Attributes
//V               = #30.
//
#16390 = type;
#16386 = class;
#8197  = struct;
#16389 = symbol;
#16384 = constructor;
//enum            = #8198.
#8195  = sealed;
#8193  = embeddable;
//template        = #16391.
//extension       = #8203.
//
#8201  = const;
#8208  = singleton;
//generic         = #8202.
#8194  = static;
#16385 = var;
#50    = auto;
#8196  = interface;
#16392 = property;
#16393 = method;
//__loop          = #16394.
////nonstructural   = #8204.
//import          = #16395.
#16396 = extern;
#8205  = closure;
//mixin           = #8206.
#16399 = get;
//__block         = #16400.
//__nested        = #16401.
//preloaded       = #8207.
#16387 = cast;
#16404 = new;
#16405 = forward;
#16406 = set;
#16407 = field;

#8210  = abstract;
#8211  = public;
//private         = #8212.
#8213  = internal;
#8214  = closed;
//predefined      = #8215.
#8216  = dispatch;

//__args          = #32. 
//
#8200  = __string;
#10    = __int;
#11    = __raw;
//__ptr           = #12.
//__real          = #15.
//__dword         = #16.
//__mssg          = #19.
//__subj          = #18.
//__extmssg       = #21.
////__tape_mixin    = #8209.
//__symbol        = #22.
//dynamic         = #30.
//stackunsafe     = #16403.
//
//__ifoperator    = #4097.
//__ifnotoperator = #4098.
//
/// Provides classes that describe the basic functionality

type object     = system'Object;

// === basic logical types ===
type bool       = system'BoolValue;

// === basic type aliases ===
type byte       = system'ByteNumber;
type short      = system'ShortNumber;
type int        = system'IntNumber;
//type uint       = system'UIntNumber.
//type long       = system'LongNumber.
//type real       = system'RealNumber.
//type char       = system'CharValue.
//type mssg       = system'Message.
////type ext_mssg   = system'ExtensionMessage.
type literal    = system'LiteralValue;
type wide       = system'WideLiteralValue;
type handle     = system'Handle;
//type rt_ptr     = system'RTPointer.
//type dirty_ptr  = system'UnsafePointer.