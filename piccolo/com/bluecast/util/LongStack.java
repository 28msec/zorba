/*
 * $Id: LongStack.java,v 1.3 2004/07/08 08:01:45 yuvalo Exp $
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

package  com.bluecast.util;


/**
 * A stack of native longs.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.3 $
 */
final public class LongStack {
    private long[] stack;
    private int pos;            // position of the top of the stack

    public LongStack (int initialSize) {
        stack = new long[initialSize];
        pos = -1;
    }

    public long pop () {
        if (pos >= 0) {
            return  stack[pos--];
        }
        else
            throw  new ArrayIndexOutOfBoundsException("stack underflow");
    }

    public void push (long s) {
        if (pos + 1 < stack.length) {
            stack[++pos] = s;
        }
        else {
            setSize(stack.length*2);
            stack[++pos] = s;
        }
    }

    public void setSize (int newSize) {
        if (newSize != stack.length) {
            long[] newStack = new long[newSize];
            System.arraycopy(stack, 0, newStack, 0, Math.min(stack.length,
                    newSize));
            stack = newStack;
        }
    }

    public void clear () {
        pos = -1;
    }

    public int size () {
        return  pos + 1;
    }
}



