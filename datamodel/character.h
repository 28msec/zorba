/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: characters.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_CHARACTER_H
#define XQP_CHARACTER_H

namespace xqp {

#define DEPENDS_ON_CURRENT_ITEM				1
#define DEPENDS_ON_CONTEXT_ITEM				(1<<1)
#define DEPENDS_ON_POSITION						(1<<2)
#define DEPENDS_ON_LAST								(1<<3)
#define DEPENDS_ON_CONTEXT_DOCUMENT		(1<<4)
#define DEPENDS_ON_CURRENT_GROUP			(1<<5)
#define DEPENDS_ON_REGEX_GROUP				(1<<6)
#define DEPENDS_ON_LOCAL_VARIABLES		(1<<7)
#define DEPENDS_ON_USER_FUNCTIONS			(1<<8)
#define DEPENDS_ON_FOCUS  						(DEPENDS_ON_CONTEXT_ITEM \
            														| DEPENDS_ON_POSITION \
            														| DEPENDS_ON_LAST \
            														| DEPENDS_ON_CONTEXT_DOCUMENT)
#define DEPENDS_ON_NON_DOC_FOCUS			(DEPENDS_ON_CONTEXT_ITEM \
            														| DEPENDS_ON_POSITION \
            														| DEPENDS_ON_LAST)
#define ALLOWS_ZERO										(1<<13)
#define ALLOWS_ONE										(1<<14)
#define ALLOWS_MANY										(1<<15)
#define CARDINALITY_MASK							(ALLOWS_ZERO | ALLOWS_ONE | ALLOWS_MANY)
#define ALLOWS_ONE_OR_MORE 						(ALLOWS_ONE  | ALLOWS_MANY)
#define ALLOWS_ZERO_OR_MORE						(ALLOWS_ZERO | ALLOWS_ONE | ALLOWS_MANY)
#define ALLOWS_ZERO_OR_ONE						(ALLOWS_ZERO | ALLOWS_ONE)
#define EXACTLY_ONE										ALLOWS_ONE
#define EMPTY													ALLOWS_ZERO


/*______________________________________________________________________
|  
|	Expression whose item type is node, when the nodes in the result 
|	are guaranteed all to be in the same document as the context node.
|	For expressions that return values other than nodes, the setting is 
|	undefined. 
|_______________________________________________________________________*/
#define CONTEXT_DOCUMENT_NODESET			(1<<16)

/*______________________________________________________________________
|  
|	Expression whose item type is node, when the nodes in the result 
|	are in document order. 
|_______________________________________________________________________*/
#define ORDERED_NODESET								(1<<17)

/*______________________________________________________________________
|  
|	Expression that delivers items in the reverse of the correct order, 
|	when unordered retrieval is requested. 
|_______________________________________________________________________*/
#define REVERSE_DOCUMENT_ORDER				(1<<18)

/*______________________________________________________________________
|  
|	Expression that delivers a set of nodes with the guarantee that no 
|	node in the set will be an ancestor of any other. This property is 
|	useful in deciding whether the results of a path expression are 
|	pre-sorted. The property is only used in the case where the 
|	NATURALLY_SORTED property is true, so there is no point in setting it 
|	in other cases. 
|_______________________________________________________________________*/
#define PEER_NODESET									(1<<19)

/*______________________________________________________________________
|  
|	Expression that delivers a set of nodes with the guarantee that 
|	every node in the result will be a descendant or self, or attribute
|	or namespace, of the context node 
|_______________________________________________________________________*/
#define SUBTREE_NODESET								(1<<20)

/*______________________________________________________________________
|  
|	Expression that delivers a set of nodes with the guarantee that 
|	every node in the result will be an attribute or namespace of the 
|	context node 
|_______________________________________________________________________*/
#define ATTRIBUTE_NS_NODESET					(1<<21)

/*______________________________________________________________________
|  
|	Expression that will never return newly created nodes, nor a value 
|	that depends on the identity of newly created nodes. Expressions that 
|	do create new nodes cannot be moved out of loops as this could cause 
|	too few nodes to be created. 
|_______________________________________________________________________*/
#define NON_CREATIVE									(1<<22)

/*______________________________________________________________________
|  
|	Expression that delivers a set of nodes that are all in the same 
|	document (not necessarily the same document as the context node). 
|_______________________________________________________________________*/
#define SINGLE_DOCUMENT_NODESET				(1<<23)

/*______________________________________________________________________
|  
|	Expression that might have side-effects.
|_______________________________________________________________________*/
#define HAS_SIDE_EFFECTS							(1<<24)



class character
{
public:
	// Reduce the cardinality value to an integer in the range 0-7
  static uint32_t get_cardinality_code(uint32_t cardinality);

	// Display the cardinality value as a string
	static std::string describe(uint32_t cardinality);

private:
	character() {}
	~character() {}

};


} /* namespace xqp */
#endif /* XQP_CHARACTER_H */
