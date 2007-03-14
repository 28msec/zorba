/*
 * $Id: IndexedObjectImpl.java,v 1.3 2004/07/08 08:01:45 yuvalo Exp $
 *
 * (C) Copyright 2002-2004 by Yuval Oren. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


package com.bluecast.util;

final public class IndexedObjectImpl implements IndexedObject {
    private int index;
    private Object object;

    public IndexedObjectImpl(int index, Object object) {
        this.index = index;
        this.object = object;
    }

    final public int getIndex() { return index; }
    final public void setIndex(int index) { this.index = index; }

    final public Object getObject() { return object; }
    final public void setObject(Object object) { this.object = object; }

    final public Object clone() {
        return new IndexedObjectImpl(index,object);
    }

    final public boolean equals(Object o) {
        if (o instanceof IndexedObject) {
            IndexedObject i = (IndexedObject) o;
            return (index == i.getIndex() && object.equals(i.getObject()));
        }
        else {
            return false;
        }
    }
}
