# Copyright 2006-2011 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require '@rubyPath@/zorba_api'
 
def test(zorba)
  print 'Executing: test08.xq'  + "\n"
  lines = '(1, xs:int(2),"bla", <a><b att="{(3, xs:int(4),"foo", "bar")}"/>text<!--a comment--><?pi?></a>)' 
  xquery = zorba.compileQuery(lines) 
  result = xquery.execute() 
  print result  + "\n"
 
  print "Iterator:"  + "\n"
  iterator = xquery.iterator() 
  printIterator(iterator, "")
  xquery.destroy()
  
end


def printIterator(iterator, pre)
  item = Zorba_api::Item.createEmptyItem()
  iterator.open() 
  while iterator.next(item)
    printItem(item, pre)
  end
  iterator.close()
  iterator.destroy()
end
 
def printItem(item, pre)
  if item.isAtomic():
    typeItem = item.getType()
    print pre + "Leaf Atomic: '" + item.getStringValue() + "' \ttype:", typeItem.getStringValue() + "\n"
    return
  end
  
  if item.isNode():
    kind = item.getNodeKind()
  
    if kind ==  0 # anyNode
      print pre + 'Any node' + "\n"
      print pre + "  Children:" + "\n"
      printIterator(item.getChildren(), pre+"    ")
    end
    if kind ==  1 # doc
      print pre + 'Doc' + "\n"
      print pre + "  Children:" + "\n"
      printIterator(item.getChildren(), pre+"    ")
    end
    if kind == 2 # element
      nodeName = Zorba_api::Item.createEmptyItem()
      item.getNodeName(nodeName)
      typeItem = item.getType()              
      print pre + "Start Element: ", nodeName.getStringValue() + " \ttype:", typeItem.getStringValue() + "\n"
      print pre + "  Attributes:" + "\n"
      printIterator(item.getAttributes(), pre+"    ")
      print pre + "  Children:" + "\n"
      printIterator(item.getChildren(), pre+"    ")
      print pre + "End  Element: " + nodeName.getStringValue() + "\n"
    end
    if kind == 3 # attribute
      nodeName = Zorba_api::Item.createEmptyItem()
      item.getNodeName(nodeName)
      typeItem = item.getType()              
      print pre + "Attribute: " + nodeName.getStringValue() + "= '" + item.getStringValue() + "'"" \ttype:" + typeItem.getStringValue() + "\n"
      print pre+"  Atomization value:" + "\n"
      printIterator(item.getAtomizationValue(), pre+"    ")
    end
    if kind == 4 # text
      typeItem = item.getType()              
      print pre + "Text: " + item.getStringValue() + " \ttype:", typeItem.getStringValue() + "\n"
      print pre+"  Atomization value:" + "\n"
      printIterator(item.getAtomizationValue(), pre+"    ")
    end
    if kind == 5 # pi
      nodeName = Zorba_api::Item.createEmptyItem()
      item.getNodeName(nodeName)
      print pre + "Pi: " + nodeName.getStringValue() + "\n"
    end
    if kind == 6 # comment
      print pre + "Comment: " + item.getStringValue() + "\n"
    end
  else
    print pre+"Item not Node, not Atomic" + "\n"
  end
end

store = Zorba_api::InMemoryStore.getInstance()
zorba = Zorba_api::Zorba.getInstance(store)

print "Running: XQuery execute - Get Iterator and print info from its items"  + "\n"
test(zorba)
print "Success" + "\n"

zorba.shutdown()
Zorba_api::InMemoryStore.shutdown(store)
