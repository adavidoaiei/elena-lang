//---------------------------------------------------------------------------
//		E L E N A   P r o j e c t:  ELENA Compiler
//
//		This file contains ELENA Engine Syntax Tree classes
//
//                                              (C)2005-2020, by Alexei Rakov
//---------------------------------------------------------------------------

#ifndef syntaxTreeH
#define syntaxTreeH 1

namespace _ELENA_
{

// --- SyntaxType ---

enum LexicalType
{
//   lxSimpleMask               = 0x002000,
//   lxCodeScopeMask            = 0x004000,
//   lxExprMask                 = 0x00C000,
//   lxSubOpMask                = 0x100000,
//   lxPrimitiveOpMask          = 0x080000,
   lxTerminalMask             = 0x002000,
   lxObjectMask               = 0x018000,
   lxStatementMask            = 0x010000,
   lxOperatorMask             = 0x020000,
   lxOpScopeMask              = 0x040000,

//   lxInvalid                  = -2,
   lxNone                     = 0x000000,

   // scopes
   lxRoot                     = 0x000001,
   lxIdle                     = 0x000002,
   lxNamespace                = 0x000003,

   lxSymbol                   = 0x000010,
   lxClass                    = 0x000011,
   lxImport                   = 0x000012,
   lxClassMethod              = 0x000013,
   lxConstructor              = 0x000014,
   lxParent                   = 0x000015,
   lxClassField               = 0x000016,
   lxRedirect                 = 0x000017,
   lxTemplate                 = 0x000018,
   lxMethodParameter          = 0x000019,
   lxStaticMethod             = 0x00001A,
   lxForward                  = 0x00001B,
   lxClassProperty            = 0x00001C,
   lxClassImport              = 0x00001D,
   lxFinalblock               = 0x00001E,
   lxExtensionTemplate        = 0x00001F,

   // derivation symbols
   lxToken                    = 0x001010,
   lxScope                    = 0x001020,
   lxAttributeDecl            = 0x001030,    
   lxSizeDecl                 = 0x001040,
   lxBaseDecl                 = 0x001050,
   lxCode                     = 0x011060,
   lxDispatchCode             = 0x001070,
   lxMessage                  = 0x021080,   // arg - message
   lxNewOperation             = 0x021081,
   lxCastOperation            = 0x021082,
   lxEOP                      = 0x011090,   // end of the code block
   lxAssign                   = 0x0210A0,
   lxTemplateArgs             = 0x0010B0,
   lxNestedClass              = 0x0010C0,
   lxParameter                = 0x0010D0,
   lxPropertyParam            = 0x0010E0,
   lxOperator                 = 0x0210F0,
   lxStatementDecl            = 0x001100,
   lxControlArgs              = 0x001110,
   lxFieldInit                = 0x001120,
   lxStaticFieldInit          = 0x001121,
   lxDynamicSizeDecl          = 0x001130,
   lxClosureExpr              = 0x001140,
   lxInlineDecl               = 0x001150,
   lxInlineAttribute          = 0x001160,
   lxFieldAccum               = 0x001170,
   lxArrOperator              = 0x021180,
   lxAttrExpression           = 0x001190,
   lxPropertyDecl             = 0x0011A0,
   lxSwitchOption             = 0x0011B0,
   lxLastSwitchOption         = 0x0011C0,
   lxCollection               = 0x0211D0,
   lxTemplateOperator         = 0x0011D0,
   lxInlineArgs               = 0x0011E0,

   // derivation terminals
   lxEOF                      = 0x002010,   // end of the file
   lxIdentifier               = 0x002011,
   lxHexInteger               = 0x002012,
   lxReference                = 0x002013,
   lxGlobalReference          = 0x002014,
   lxInteger                  = 0x002015,
   lxLiteral                  = 0x002016,
   lxMetaConstant             = 0x002017,
   lxWide                     = 0x002018,
   lxCharacter                = 0x002019,
   lxLong                     = 0x00201A,
   lxReal                     = 0x00201B,
   lxExplicitConst            = 0x00201C,

   lxVirtualReference         = 0x00201F,

   // expression nodes
   lxExpression               = 0x059030,
   lxSeqExpression            = 0x059031,
   lxBoxableExpression        = 0x059032,
   lxFieldExpression          = 0x059033,
   lxArgBoxableExpression     = 0x059034,
   lxCodeExpression           = 0x059035,
   lxCondBoxableExpression    = 0x059036,
   lxPrimArrBoxableExpression = 0x059037,
   lxNestedSeqExpression      = 0x059038,
   lxNil                      = 0x018040,
   lxStopper                  = 0x018041,   // used for variadic arguments as a last argument
   lxClassSymbol              = 0x018050,   // arg - reference
   lxSymbolReference          = 0x058060,
   lxConstantSymbol           = 0x018070,   // arg - reference
   lxImporting                = 0x018090,
   lxCalling_0                = 0x0580A0,   // calling a method, arg - message
   lxCalling_1                = 0x0580A1,
   lxDirectCalling            = 0x0580A2, 
   lxSDirectCalling           = 0x0580A3,
   lxInlineArgCall            = 0x0580A4,
   lxCurrent                  = 0x0180B0,   // arg - offset
   lxResult                   = 0x0180C0,   // arg - offset
   lxNewFrame                 = 0x0500D0,   // if argument -1 - than with presaved message
   lxCreatingClass            = 0x0580E0,   // arg - count
   lxCreatingStruct           = 0x0580F0,   // arg - size
   lxVariable                 = 0x010100,
   lxIntVariable              = 0x010101,
   lxIntsVariable             = 0x010102,
   lxBytesVariable            = 0x010103,
   lxShortsVariable           = 0x010104,
   lxBinaryVariable           = 0x010105,
   lxParamsVariable           = 0x010106,
   lxLongVariable             = 0x010107,
   lxReal64Variable           = 0x010108,
   lxLocal                    = 0x018110,   // arg - offset
   lxSelfLocal                = 0x018111,
   lxLocalAddress             = 0x018112,   // arg - offset
   lxTempLocal                = 0x018113,
   lxBlockLocalAddr           = 0x018114, // arg - offset
   lxAssigning                = 0x058120,   // an assigning expression, arg - size
   lxCopying                  = 0x058121,
   lxByRefAssigning           = 0x058122,
   lxSaving                   = 0x058123,
   lxCondCopying              = 0x058124,
   lxFloatSaving              = 0x058125,
   lxCondAssigning            = 0x058126,
   lxReturning                = 0x059130,
   lxImplicitJump             = 0x058140,
   lxBranching                = 0x058150,   // branch expression      
   lxIf                       = 0x058160,   // optional arg - reference
   lxElse                     = 0x058161,   // optional arg - reference
   lxIfN                      = 0x058162,
   lxIfNotN                   = 0x058163,
   lxIfNot                    = 0x058164,
   lxLooping                  = 0x058165,
   lxLessN                    = 0x058166,
   lxNotLessN                 = 0x058167,
   lxGreaterN                 = 0x058168,
   lxNotGreaterN              = 0x058169,
   lxResendExpression         = 0x059170,
   lxDispatching              = 0x059171,   // dispatching a message, optional arg - message
   lxMultiDispatching         = 0x058180,
   lxSealedMultiDispatching   = 0x058181,
   lxResending                = 0x058190,   // resending a message, optional arg - message / -1 (if follow-up operation is available)
   lxGenericResending         = 0x058191,   // resending a generic message
   lxConstantInt              = 0x0181A0,   // arg - reference
   lxConstantString           = 0x0181A1,   // arg - reference
   lxConstantList             = 0x0181A2,   // arg - reference
   lxConstantWideStr          = 0x0181A3,   // arg - reference
   lxConstantChar             = 0x0181A4,   // arg - reference
   lxConstantLong             = 0x0181A5,   // arg - reference
   lxConstantReal             = 0x0181A6,   // arg - reference
   lxMessageConstant          = 0x0181A7, // arg - rererence
   lxSubjectConstant          = 0x0181A8, // arg - reference
   lxExtMessageConstant       = 0x0181A9, // arg -reference
   lxOp                       = 0x0581B0,
   lxIntOp                    = 0x0581B1,   // arg - operation id
   lxIntBoolOp                = 0x0581B2,   // arg - operation id
   lxLongOp                   = 0x0581B3,   // arg - operation id
   lxLongBoolOp               = 0x0581B4,   // arg - operation id
   lxRealOp                   = 0x0581B5,   // arg - operation id
   lxRealBoolOp               = 0x0581B6,   // arg - operation id
   lxNilOp                    = 0x0581B7,   // arg - operation id
   lxRealIntOp                = 0x0581B8,   // arg - operation id
   lxField                    = 0x0181C0,   // arg - offset
   lxFieldAddress             = 0x0181C1,   // arg - offset
   lxStaticField              = 0x0181C2,   // arg - reference   // - lxClassStaticField
   lxClassRef                 = 0x0181C3,
   lxStaticConstField         = 0x0181C4,
   lxNewArrOp                 = 0x0581D0,
   lxInitializing             = 0x0581E0,
   lxCloning                  = 0x0581E1,
   lxInternalCall             = 0x0581F0,   // calling an internal function, arg - reference
   lxStdExternalCall          = 0x058200,   // calling an external function, arg - reference
   lxExternalCall             = 0x058201,   // calling an external function, arg - reference
   lxCoreAPICall              = 0x058202,   // calling an external function, arg - reference
   lxExtIntConst              = 0x018210,
   lxExtIntArg                = 0x018211,
   lxTrying                   = 0x058220,   // try-catch expression
   lxAlt                      = 0x058221,   // alt-catch expression
   lxArgArrOp                 = 0x058230,
   lxIntArrOp                 = 0x058231,   // arg - operation id
   lxShortArrOp               = 0x058232,
   lxByteArrOp                = 0x058233,
   lxArrOp                    = 0x058234,   // arg - operation id
   lxBinArrOp                 = 0x058235,
   lxBoolOp                   = 0x058236,   // arg - operation id
   lxExternFrame              = 0x058240,
   lxSwitching                = 0x059250,
   lxOption                   = 0x058251,
   lxYieldDispatch            = 0x058260,
   lxYieldReturning           = 0x058261,
   lxYieldContext             = 0x018270,
   lxYieldLocals              = 0x018271,
   lxArgArray                 = 0x058280,
   lxCondBoxing               = 0x058290,
   lxIndexSaving              = 0x0582A0,
   lxIndexLoading             = 0x0582A1,

   // attributes
   lxAttribute                = 0x000F00,
   lxNameAttr                 = 0x000F01,
   lxSourcePath               = 0x000F02,
   lxCol                      = 0x000F03,
   lxRow                      = 0x000F04,
   lxLength                   = 0x000F05,
   lxBreakpoint               = 0x000F06,
   lxAutogenerated            = 0x000F07,
   lxArgCount                 = 0x000F08,
   lxType                     = 0x000F09,   // arg - reference
   lxClassFlag                = 0x000F0A,   // class fields
   lxCallTarget               = 0x000F0B,   // arg - reference
   lxLevel                    = 0x000F0C,
   lxAllocated                = 0x000F0D,
   lxMessageVariable          = 0x000F0E,   // debug info only
   lxSelfVariable             = 0x000F0F,   // debug info only
   lxAutoMultimethod          = 0x000F10,
   lxConstAttr                = 0x000F11,
   lxTemplateParam            = 0x000F12,
   lxSize                     = 0x000F13,
   lxReserved                 = 0x000F14,
   lxIntValue                 = 0x000F16,   // arg - integer value
   lxTemplateIdentParam       = 0x000F17,
   lxArrayType                = 0x000F18,
   lxMember                   = 0x000F19,  // a collection member, arg - offset
   lxStaticAttr               = 0x000F1A,
   lxEmbeddableAttr           = 0x000F1B,
   lxBookmark                 = 0x000F1C,
   lxBookmarkReference        = 0x000F1D,
   lxInternalRef              = 0x000F1E,
   lxClassName                = 0x000F1F, // arg - identifier
   lxIfValue                  = 0x000F20, // arg - reference
   lxElseValue                = 0x000F21, // arg - reference
   lxTemplateNameParam        = 0x000F22,
   lxEmbeddableMssg           = 0x000F23,
   lxBinarySelf               = 0x000F24, // debug info only
   lxStatConstRef             = 0x000F25, 
   lxStatIndex                = 0x000F26,
   lxRetEmbeddableAttr        = 0x000F27,
   lxElementType              = 0x000F28, // arg - reference
   lxSubjectRef               = 0x000F29, // arg - reference
   lxLongMode                 = 0x000F2A,
};

// --- SyntaxTree ---

class SyntaxTree
{
   MemoryDump _body;
   MemoryDump _strings;

public:
   struct NodePattern;

   // --- Node ---
   class Node
   {
      friend class SyntaxTree;

      SyntaxTree* tree;
      pos_t       position;

      Node(SyntaxTree* tree, pos_t position, LexicalType type, ref_t argument, int strArgument);

      Node appendStrNode(LexicalType nodeType, int strOffset)
      {
         return tree->read(tree->appendChild(position, nodeType, 0, strOffset));
      }
      Node injectStrNode(LexicalType nodeType, int strOffset)
      {
         pos_t child = tree->getChild(position);
         if (child != INVALID_REF) {
            return tree->read(tree->injectChild(child, nodeType, 0, strOffset));
         }
         else return appendStrNode(nodeType, strOffset);
      }
      Node insertStrNode(LexicalType nodeType, int strOffset)
      {
         return tree->read(tree->insertChild(position, nodeType, 0, strOffset));
      }

   public:
      LexicalType   type;
      ref_t         argument;
      pos_t         strArgument;   // if strArgument is not -1 - it contains the position of the argument string

//      SyntaxTree* Tree()
//      {
//         return tree;
//      }

      ident_t identifier()
      {
         if (strArgument != INVALID_REF) {
            return (const char*)(tree->_strings.get(strArgument));
         }
         else return nullptr;
      }

      operator LexicalType() const { return type; }

      bool operator == (LexicalType operand)
      {
         return this->type == operand;
      }
      bool operator != (LexicalType operand)
      {
         return this->type != operand;
      }

      bool operator == (Node operand)
      {
         return this->position == operand.position && this->tree == operand.tree;
      }
      bool operator != (Node operand)
      {
         return this->position != operand.position || this->tree != operand.tree;
      }

      void operator = (LexicalType operand)
      {
         this->type = operand;

         MemoryReader reader(&tree->_body, position - 12);

         tree->save(*this);
      }

      void set(LexicalType type, ref_t argument)
      {
         this->type = type;
         this->argument = argument;
         this->strArgument = INVALID_REF;

         tree->save(*this);
      }
      void set(LexicalType type, ident_t argument)
      {
         this->type = type;
         this->argument = 0;
         this->strArgument = tree->saveStrArgument(argument);

         tree->save(*this);
      }

      void setArgument(ref_t argument)
      {
         this->argument = argument;
         this->strArgument = INVALID_REF;

         tree->save(*this);
      }
      void setStrArgument(ident_t argument)
      {
         this->strArgument = tree->saveStrArgument(argument);

         tree->save(*this);
      }

      void setArgument(int argument)
      {
         setArgument((ref_t)argument);
      }

      Node firstChild() const
      {
         if (tree != NULL) {
            return tree->read(tree->getChild(position));
         }
         else return Node();
      }

      Node firstChild(LexicalType mask) const
      {
         Node current = firstChild();

         while (current != lxNone && !test(current.type, mask))
            current = current.nextNode();

         return current;
      }

      Node findNext(LexicalType mask) const
      {
         Node current = *this;

         while (current != lxNone && !test(current.type, mask))
            current = current.nextNode();

         return current;
      }

      Node findSubNodeMask(LexicalType mask)
      {
         Node current = firstChild(mask);
         if (current == lxExpression) {
            return current.findSubNodeMask(mask);
         }
         else return current;
      }

      Node findSubNode(LexicalType type)
      {
         Node current = firstChild();
         while (current != lxNone && current.type != type) {
            if (current == lxExpression) {
               Node subNode = current.findSubNode(type);
               if (subNode != lxNone)
                  return subNode;
            }
            current = current.nextNode();
         }

         return current;
      }
      Node findSubNode(LexicalType type1, LexicalType type2)
      {
         Node current = firstChild();
         while (current != lxNone && current.type != type1) {
            if (current == lxExpression) {
               Node subNode = current.findSubNode(type1, type2);
               if (subNode != lxNone)
                  return subNode;
            }
            else if (current == type2)
               break;

            current = current.nextNode();
         }

         return current;
      }
      Node findSubNode(LexicalType type1, LexicalType type2, LexicalType type3)
      {
         Node current = firstChild();
         while (current != lxNone && current.type != type1) {
            if (current == lxExpression) {
               Node subNode = current.findSubNode(type1, type2, type3);
               if (subNode != lxNone)
                  return subNode;
            }
            else if (current == type2)
               break;
            else if (current == type3)
               break;

            current = current.nextNode();
         }

         return current;
      }

      //Node findSubNode(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4)
      //{
      //   Node child = firstChild();
      //   while (child != lxNone && child.type != type1) {
      //      if (child == lxExpression) {
      //         Node subNode = child.findSubNode(type1, type2, type3, type4);
      //         if (subNode != lxNone)
      //            return subNode;
      //      }
      //      else if (child == type2)
      //         break;
      //      else if (child == type3)
      //         break;
      //      else if (child == type4)
      //         break;

      //      child = child.nextNode();
      //   }

      //   return child;
      //}

      //Node findSubNode(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5)
      //{
      //   Node child = firstChild();
      //   while (child != lxNone && child.type != type1) {
      //      if (child == lxExpression) {
      //         Node subNode = child.findSubNode(type1, type2, type3, type4);
      //         if (subNode != lxNone)
      //            return subNode;
      //      }
      //      else if (child == type2)
      //         break;
      //      else if (child == type3)
      //         break;
      //      else if (child == type4)
      //         break;
      //      else if (child == type5)
      //         break;

      //      child = child.nextNode();
      //   }

      //   return child;
      //}

      //Node findSubNode(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5, LexicalType type6)
      //{
      //   Node child = firstChild();
      //   while (child != lxNone && child.type != type1) {
      //      if (child == lxExpression) {
      //         Node subNode = child.findSubNode(type1, type2, type3, type4);
      //         if (subNode != lxNone)
      //            return subNode;
      //      }
      //      else if (child == type2)
      //         break;
      //      else if (child == type3)
      //         break;
      //      else if (child == type4)
      //         break;
      //      else if (child == type5)
      //         break;
      //      else if (child == type6)
      //         break;

      //      child = child.nextNode();
      //   }

      //   return child;
      //}

      Node lastChild() const
      {
         Node current = firstChild();
         if (current != lxNone) {
            while (current.nextNode() != lxNone) {
               current = current.nextNode();
            }
         }
         return current;
      }

      Node lastChild(LexicalType mask) const
      {
         Node current = firstChild(mask);
         if (current != lxNone) {
            Node nextNode = current.nextNode(mask);
            while (nextNode != lxNone) {
               current = nextNode;
               nextNode = nextNode.nextNode(mask);
            }
         }
         return current;
      }

      Node nextNode() const
      {
         if (tree != NULL) {
            return tree->read(tree->getNext(position));
         }
         else return Node();
      }

      Node nextNode(LexicalType mask) const
      {
         Node current = nextNode();

         while (current != lxNone && !test(current.type, mask))
            current = current.nextNode();

         return current;
      }

      Node nextSubNodeMask(LexicalType mask)
      {
         Node child = nextNode(mask);
         if (child == lxExpression) {
            return child.findSubNodeMask(mask);
         }
         else return child;
      }

      Node prevNode() const
      {
         return tree->read(tree->getPrevious(position));
      }

      Node prevNode(LexicalType mask) const
      {
         Node current = prevNode();

         while (current != lxNone && !test(current.type, mask))
            current = current.prevNode();

         return current;
      }

      Node lastNode() const
      {
         Node last = *this;
         Node current = nextNode();
         while (current != lxNone) {
            last = current;
            current = current.nextNode();
         }

         return last;
      }

      Node lastNode(LexicalType mask) const
      {
         Node last = *this;
         Node current = nextNode(mask);
         while (current != lxNone) {
            last = current;
            current = current.nextNode(mask);
         }

         return last;
      }

      Node parentNode() const
      {
         return tree->read(tree->getParent(position));
      }

      Node insertNode(LexicalType type, int argument = 0)
      {
         return tree->read(tree->insertChild(position, type, argument, INVALID_REF));
      }

      Node insertNode(LexicalType type, ident_t argument)
      {
         return tree->read(tree->insertChild(position, type, 0, tree->saveStrArgument(argument)));
      }

      Node appendNode(LexicalType type, int argument = 0)
      {
         return tree->read(tree->appendChild(position, type, argument, INVALID_REF));
      }
      Node appendNode(LexicalType type, ident_t argument)
      {
         return tree->read(tree->appendChild(position, type, 0, tree->saveStrArgument(argument)));
      }

      // inject a node in place of the current one
      void injectAndReplaceNode(LexicalType type, int argument = 0)
      {
         refresh();

         if (this->strArgument != INVALID_REF) {
            injectStrNode(this->type, this->strArgument);
         }
         else injectNode(this->type, this->argument);

         set(type, argument);
      }

      // inject a child node between the current one and its children
      Node injectNode(LexicalType type, int argument = 0)
      {
         pos_t child = tree->getChild(position);
         if (child != INVALID_REF) {
            return tree->read(tree->injectChild(child, type, argument, INVALID_REF));
         }
         else return appendNode(type, argument);
      }
      Node injectNode(LexicalType type, ident_t argument)
      {
         pos_t child = tree->getChild(position);
         if (child != INVALID_REF) {
            return tree->read(tree->injectChild(child, type, 0, tree->saveStrArgument(argument)));
         }
         else return appendNode(type, argument);
      }

      Node prependSibling(LexicalType type, int argument = 0)
      {
         return tree->read(tree->insertSibling(position, type, argument, INVALID_REF));
      }
      Node prependSibling(LexicalType type, ident_t argument)
      {
         return tree->read(tree->insertSibling(position, type, 0, tree->saveStrArgument(argument)));
      }

      void refresh()
      {
         tree->refresh(*this);
      }

      //Node findPattern(NodePattern pattern)
      //{
      //   return tree->findPattern(*this, 1, pattern);
      //}

      Node findChild(LexicalType type)
      {
         Node current = firstChild();

         while (current != lxNone && current != type) {
            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2)
      {
         Node current = firstChild();
      
         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
      
            current = current.nextNode();
         }
      
         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;

            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;
            else if (current == type4)
               return current;

            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;
            else if (current == type4)
               return current;
            else if (current == type5)
               return current;

            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5, LexicalType type6)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;
            else if (current == type4)
               return current;
            else if (current == type5)
               return current;
            else if (current == type6)
               return current;

            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5, LexicalType type6, LexicalType type7)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;
            else if (current == type4)
               return current;
            else if (current == type5)
               return current;
            else if (current == type6)
               return current;
            else if (current == type7)
               return current;

            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5, LexicalType type6, LexicalType type7, LexicalType type8)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;
            else if (current == type4)
               return current;
            else if (current == type5)
               return current;
            else if (current == type6)
               return current;
            else if (current == type7)
               return current;
            else if (current == type8)
               return current;

            current = current.nextNode();
         }

         return current;
      }
      Node findChild(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5, LexicalType type6, LexicalType type7, LexicalType type8, LexicalType type9)
      {
         Node current = firstChild();

         while (current != lxNone && current != type1) {
            if (current == type2)
               return current;
            else if (current == type3)
               return current;
            else if (current == type4)
               return current;
            else if (current == type5)
               return current;
            else if (current == type6)
               return current;
            else if (current == type7)
               return current;
            else if (current == type8)
               return current;
            else if (current == type9)
               return current;

            current = current.nextNode();
         }

         return current;
      }

      bool existChild(LexicalType type)
      {
         return findChild(type) == type;
      }
      bool existChild(LexicalType type1, LexicalType type2)
      {
         return findChild(type1, type2) != lxNone;
      }
      bool existChild(LexicalType type1, LexicalType type2, LexicalType type3)
      {
         return findChild(type1, type2, type3) != lxNone;
      }
      bool existSubChild(LexicalType type1, LexicalType type2)
      {
         return findSubNode(type1, type2) != lxNone;
      }
      //bool existSubChild(LexicalType type1)
      //{
      //   return findSubNode(type1) != lxNone;
      //}

      bool compare(LexicalType type1, LexicalType type2)
      {
         return (this->type == type1) || (this->type == type2);
      }
      bool compare(LexicalType type1, LexicalType type2, LexicalType type3)
      {
         return (this->type == type1) || (this->type == type2) || (this->type == type3);
      }
      bool compare(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4)
      {
         return (this->type == type1) || (this->type == type2) || (this->type == type3) || (this->type == type4);
      }
      bool compare(LexicalType type1, LexicalType type2, LexicalType type3, LexicalType type4, LexicalType type5)
      {
         return (this->type == type1) || (this->type == type2) || (this->type == type3) 
            || (this->type == type4) || (this->type == type5);
      }

      Node()
      {
         type = lxNone;
         position = argument = 0;
         strArgument = INVALID_REF;

         tree = NULL;
      }
   };

   // --- SyntaxWriter ---
   class Writer
   {
      friend class SyntaxTree;

      SyntaxTree* _syntaxTree;
      Stack<pos_t> _bookmarks;
      pos_t        _current;
      int          _pendingBookmarks;

      void insertPendingBookmarks(pos_t position)
      {
         while (_pendingBookmarks) {
            _bookmarks.push(position);
            _pendingBookmarks--;
         }
      }

      void inject(pos_t position, LexicalType type, ref_t argument, pos_t strArgRef);
      void insert(LexicalType type, ref_t argument, pos_t strArgRef, bool newMode);

   public:
      bool hasBookmarks() const
      {
         return _bookmarks.Count() != 0;
      }

      int newBookmark()
      {
         _pendingBookmarks++;

         return _bookmarks.Count() + _pendingBookmarks;
      }

      void trim();

      void removeBookmark()
      {
         if (_pendingBookmarks > 0) {
            _pendingBookmarks--;
         }
         else _bookmarks.pop();
      }

      void clear()
      {
         _syntaxTree->clear();
         _bookmarks.clear();
         _current = INVALID_REF;
         _pendingBookmarks = 0;
      }

      void inject(LexicalType type, ident_t argument)
      {
         inject(_bookmarks.peek(), type, 0, _syntaxTree->saveStrArgument(argument));
      }
      void inject(LexicalType type, ref_t argument)
      {
         inject(_bookmarks.peek(), type, argument, INVALID_REF);
      }
      void inject(LexicalType type)
      {
         inject(_bookmarks.peek(), type, 0, INVALID_REF);
      }
      void newNode(LexicalType type, ref_t argument);
      void newNode(LexicalType type, int argument)
      {
         newNode(type, (ref_t)argument);
      }
      void newNode(LexicalType type, ident_t argument);
      void newNode(LexicalType type)
      {
         newNode(type, 0u);
      }
      void appendNode(LexicalType type, ref_t argument)
      {
         newNode(type, argument);
         closeNode();
      }
      void appendNode(LexicalType type, int argument)
      {
         newNode(type, argument);
         closeNode();
      }
      void appendNode(LexicalType type, ident_t argument)
      {
         newNode(type, argument);
         closeNode();
      }
      void appendNode(LexicalType type)
      {
         newNode(type);
         closeNode();
      }
      void insertNode(LexicalType type)
      {
         insert(type, 0, INVALID_REF, false);
      }
      void insertNode(LexicalType type, int argument)
      {
         insert(type, argument, INVALID_REF, false);
      }
      void newPrependedNode(LexicalType type, int argument)
      {
         insert(type, argument, INVALID_REF, true);
      }

      void closeNode();

      bool seekUp(LexicalType type);
      bool seekUp(LexicalType type1, LexicalType type2);
      void findRoot()
      {
         if (_current == INVALID_REF && !_syntaxTree->isEmpty()) {
            _current = 0;
         }
      }

      Node CurrentNode();

      Writer(SyntaxTree& tree)
      {
         _current = INVALID_REF;
         _syntaxTree = &tree;
         _pendingBookmarks = 0;
      }
      Writer(Writer& writer)
      {
         _current = writer._current;
         _syntaxTree = writer._syntaxTree;
         _pendingBookmarks = 0;
      }
   };

   struct NodePattern
   {
      LexicalType type;
      LexicalType followType;
      int         argument;
      int         patternId;

      bool match(Node node)
      {
         if (node.type == type) {
            if (followType != lxNone) {
               return SyntaxTree::existSibling(node, followType);
            }
            return true;
         }
         else return false;
      }

      bool operator ==(NodePattern node) const
      {
         return (this->type == node.type && this->followType == node.followType);
      }

      bool operator !=(NodePattern node) const
      {
         return (this->type != node.type || this->followType != node.followType);
      }

      NodePattern()
      {
         this->type = lxNone;
         this->followType = lxNone;
         this->argument = 0;
         this->patternId = 0;
      }
      NodePattern(LexicalType type)
      {
         this->type = type;
         this->followType = lxNone;
         this->argument = 0;
         this->patternId = 0;
      }
      NodePattern(LexicalType type, int argument)
      {
         this->type = type;
         this->followType = lxNone;
         this->argument = argument;
         this->patternId = 0;
      }
      NodePattern(LexicalType type, int argument, int patternId)
      {
         this->type = type;
         this->followType = lxNone;
         this->argument = argument;
         this->patternId = patternId;
      }
   };

private:
   pos_t saveStrArgument(ident_t strArgument);

   pos_t newRoot(LexicalType type, int argument, pos_t strArgumentRef);
   pos_t appendChild(pos_t position, LexicalType type, int argument, pos_t strArgumentRef);  // append a child to the end
   pos_t insertChild(pos_t position, LexicalType type, int argument, pos_t strArgumentRef);  // insert a child at the start 
   pos_t insertSibling(pos_t position, LexicalType type, int argument, pos_t strArgumentRef);  // insert a child node between the current node and the node children
   pos_t injectChild(pos_t position, LexicalType type, int argument, pos_t strArgumentRef);  // insert a child node between the current node and the node children
   pos_t injectSibling(pos_t position, LexicalType type, int argument, pos_t strArgumentRef);  // insert a child node between the current node and the node children
   void clearSibling(pos_t position);
   void clearChildren(pos_t position);

   pos_t getParent(pos_t position);
   pos_t getChild(pos_t position);
   pos_t getNext(pos_t position);
   pos_t getPrevious(pos_t position);

   LexicalType getType(pos_t position);

   Node read(pos_t position);
   void save(Node& node);
   void refresh(Node& node);

public:
//   static void moveNodes(Writer& writer, SyntaxTree& buffer);
   static void copyNode(Writer& writer, LexicalType type, Node owner);
   static void copyNode(Writer& writer, Node node);
   static void copyNode(Node source, Node destination);
   static Node insertNodeCopy(Node source, Node destination);
   //   static void copyNodeSafe(Node source, Node destination, bool inclusingNode = false);
   static void saveNode(Node node, _Memory* dump, bool includingNode = false);
//   static void loadNode(Node node, _Memory* dump);
//
//   static void copyMatchedNodes(Writer& writer, LexicalType type, Node owner);

   static int countNodeMask(Node current, LexicalType mask)
   {
      int counter = 0;
      while (current != lxNone) {
         if (test(current.type, mask))
            counter++;

         current = current.nextNode();
      }

      return counter;
   }

   static int countNode(Node current, LexicalType type)
   {
      int counter = 0;
      while (current != lxNone) {
         if (current == type)
            counter++;

         current = current.nextNode();
      }

      return counter;
   }

   static int countNode(Node current, LexicalType type1, LexicalType type2)
   {
      int counter = 0;
      while (current != lxNone) {
         if (current == type1 || current == type2)
            counter++;

         current = current.nextNode();
      }

      return counter;
   }

//   static int countNode(Node current, LexicalType type1, LexicalType type2, LexicalType type3)
//   {
//      int counter = 0;
//      while (current != lxNone) {
//         if (current.compare(type1, type2, type3))
//            counter++;
//
//         current = current.nextNode();
//      }
//
//      return counter;
//   }

   static int countChild(Node node, LexicalType type)
   {
      int counter = 0;
      Node current = node.firstChild();

      while (current != lxNone) {
         if (current == type)
            counter++;

         current = current.nextNode();
      }

      return counter;
   }

//   static int countChildMask(Node node, LexicalType mask)
//   {
//      int counter = 0;
//      Node current = node.firstChild();
//
//      while (current != lxNone) {
//         if (test(current.type, mask))
//            counter++;
//
//         current = current.nextNode();
//      }
//
//      return counter;
//   }

   static int countChild(Node node, LexicalType type1, LexicalType type2)
   {
      int counter = 0;
      Node current = node.firstChild();

      while (current != lxNone) {
         if (current == type1 || current == type2)
            counter++;

         current = current.nextNode();
      }

      return counter;
   }

   static bool existChild(Node node, LexicalType type, ref_t arg)
   {
      Node current = node.firstChild();
      while (current != lxNone) {
         if (current == type && current.argument == arg)
            return true;

         current = current.nextNode();
      }

      return false;
   }

   static bool existSibling(Node node, LexicalType type1)
   {
      Node current = node.nextNode();
      while (current != lxNone) {
         if (current == type1)
            return true;

         current = current.nextNode();
      }

      return false;
   }

   static Node findPattern(Node node, int counter, ...);
//   //static bool matchPattern(Node node, int mask, int counter, ...);

   static bool existChildWithArg(Node node, LexicalType type, ref_t arg)
   {
      Node current = node.firstChild();
      while (current != lxNone) {
         if (current.type == type && current.argument == arg)
            return true;

         current = current.nextNode();
      }

      return false;
   }

   static Node goToChild(Node node, LexicalType type, ref_t arg)
   {
      Node current = node.firstChild();
      while (current != lxNone) {
         if (current.type == type && current.argument == arg)
            break;

         current = current.nextNode();
      }

      return current;
   }

   static Node findTerminalInfo(Node node);

//   //static bool apply(Node node, Trie<NodePattern>& trie);
//
//   void createRoot(LexicalType type, int argument)
//   {
//      newRoot(type, argument, INVALID_REF);
//   }
   Node readRoot();

   bool save(_Memory* section)
   {
      MemoryWriter writer(section);

      writer.writeDWord(_body.Length());
      writer.write(_body.get(0), _body.Length());

      writer.writeDWord(_strings.Length());
      writer.write(_strings.get(0), _strings.Length());

      return _body.Length() > 0;
   }

   void load(_Memory* section)
   {
      _body.clear();
      _strings.clear();

      MemoryReader reader(section);
      int bodyLength = reader.getDWord();
      _body.load(&reader, bodyLength);

      int stringLength = reader.getDWord();
      _strings.load(&reader, stringLength);
   }

   void clear()
   {
      _body.clear();
   }

   bool isEmpty()
   {
      return _body.Length() == 0;
   }

   SyntaxTree()
   {
   }
   SyntaxTree(pos_t size)
      : _body(size), _strings(size)
   {
   }
   SyntaxTree(_Memory* dump)
   {
      MemoryReader reader(dump);

      _body.load(&reader, reader.getDWord());
      _strings.load(&reader, reader.getDWord());
   }
};

void loadSyntaxTokens(Map<ident_t, int>& tokens, bool fullMode = false);

inline bool isSingleStatement(SyntaxTree::Node expr)
{
   return expr.findSubNodeMask(lxOperatorMask) == lxNone;
}

typedef SyntaxTree::Writer       SyntaxWriter;
typedef SyntaxTree::Node         SNode;
typedef SyntaxTree::NodePattern  SNodePattern;

typedef Trie<SNodePattern>           SyntaxTrie;
typedef MemoryTrieNode<SNodePattern> SyntaxTrieNode;

} // _ELENA_

#endif // syntaxTreeH
