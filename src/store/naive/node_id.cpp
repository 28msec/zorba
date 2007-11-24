
#include "util/Assert.h"
#include "store/naive/node_id.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"

namespace xqp
{


/*******************************************************************************

********************************************************************************/
OrdPathId::OrdPathId(const OrdPathId& other)
  :
  theTreeId(other.theTreeId),
  theLength(other.theLength),
  theMaxLength(other.theMaxLength)
{
  if (other.theDeweyId == other.theDeweyArray)
    theDeweyId = theDeweyArray;
  else
    theDeweyId = new long[theMaxLength];

  memcpy(theDeweyId, other.theDeweyId, theLength * sizeof(long));
}


/*******************************************************************************

********************************************************************************/
OrdPathId& OrdPathId::operator=(const OrdPathId& other)
{
  theTreeId = other.theTreeId;
  theLength = other.theLength;
  theMaxLength = other.theMaxLength;

  if (other.theDeweyId == other.theDeweyArray)
    theDeweyId = theDeweyArray;
  else
    theDeweyId = new long[theMaxLength];

  memcpy(theDeweyId, other.theDeweyId, theLength * sizeof(long));

  return *this;
}


/*******************************************************************************

********************************************************************************/
void OrdPathId::init()
{
  Assert(theDeweyId == theDeweyArray);
  Assert(theMaxLength == DEFAULT_PATH_SIZE);

  theTreeId = GET_STORE().getTreeId();

  theDeweyId[0] = 1;
  theLength = 1;
}


/*******************************************************************************

********************************************************************************/
void OrdPathId::clear()
{
  if (theDeweyId != &theDeweyArray[0])
  {
    delete [] theDeweyId;
    theDeweyId = theDeweyArray;
    theMaxLength = DEFAULT_PATH_SIZE;
  }
  theLength = 0;
}


/*******************************************************************************

********************************************************************************/
void OrdPathId::push_child()
{
  if (theLength == theMaxLength)
  {
    long* oldId = theDeweyId;
    theMaxLength *= 2;
    theDeweyId = new long[theMaxLength];
    memcpy(theDeweyId, oldId, theLength * sizeof(long));
  }
  theDeweyId[theLength] = 1;
  theLength++;
}


/*******************************************************************************

********************************************************************************/
void OrdPathId::pop_child()
{
  theLength--;
  if (theLength > 0)
    theDeweyId[theLength - 1] += 2;
}


/*******************************************************************************

********************************************************************************/
xqp_string OrdPathId::show() const
{
  std::stringstream str;

  for (unsigned long i = 0; i < theLength; i++)
  {
    str << theDeweyId[i];
    if (i < theLength-1)
      str << ".";
  }

  return str.str().c_str();
}

}
