/*
 * $Id: FileFormatException.java,v 1.3 2004/07/08 08:01:29 yuvalo Exp $
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

package com.bluecast.io;

public class FileFormatException extends java.io.IOException {
    protected int line;
    protected int column;

    public FileFormatException() {
            this(null);
    }

    public FileFormatException(String msg) {
            this(msg,-1,-1);
    }

    public FileFormatException(String msg, int line, int column) {
            super(msg);
            this.line = line;
            this.column = column;
    }

    /** Returns the line number of the bad formatting, or -1 if unknown */
    public int getLine() { return line; }

    /** Returns the column number of the bad formatting, or -1 if unknown */
    public int getColumn() { return column; }
}

