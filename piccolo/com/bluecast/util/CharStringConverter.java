/*
 * $Id: CharStringConverter.java,v 1.3 2004/07/08 08:01:45 yuvalo Exp $
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

import  java.io.*;
import  java.util.*;


/**
 * A fast way to convert character arrays into Strings. This class maintains
 * a hashtable of char[] -> String mappings. Returned Strings are guaranteed
 * to be internalized.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.3 $
 */
final public class CharStringConverter {
    private static final float DEFAULT_LOAD = 0.70F;
    private float loadFactor;
    private int numEntries = 0;
    private int maxEntries;
    private int hashmask;
    private char[][] keys;
    private String[] values;

    public CharStringConverter (int initialCapacity, float loadFactor) {
        if (initialCapacity < 0) {
            throw  new IllegalArgumentException("Illegal initial capacity: "
                    + initialCapacity);
        }
        if (loadFactor < 0 || loadFactor > 1) {
            throw  new IllegalArgumentException("Illegal load factor: " + loadFactor);
        }
        int desiredSize = (int)((float)initialCapacity/loadFactor);
        int size = 16;
        while (size < desiredSize) {
            size <<= 1;
        }
        hashmask = size - 1;
        maxEntries = (int)(size*loadFactor);
        keys = new char[size][];
        values = new String[size];
        this.loadFactor = loadFactor;
    }

    public CharStringConverter () {
        this(0, DEFAULT_LOAD);
    }

    public CharStringConverter (int initialCapacity) {
        this(initialCapacity, DEFAULT_LOAD);
    }

    /**
     * Returns the number of cached conversion mappings.
     */
    public int getCacheSize () {
        return  numEntries;
    }

    /**
     * Converts a character array into an internalized String.
     */
    public String convert (char[] ch) {
        return  convert(ch, 0, ch.length);
    }

    /**
     * Converts a character array into an internalized String.
     *
     * @param ch character array to convert
     * @param start starting offset of ch[]
     * @param length number of characters to read
     */
    public String convert (char[] ch, int start, int length) {
        if (numEntries >= maxEntries) {
            rehash();
        }
        // Look for the cached String for this char array
        int offset = hashKey(ch, start, length) & hashmask;
        char[] k = null;
        while ((k = keys[offset]) != null && !keysAreEqual(k, 0, k.length,
                ch, start, length)) {
            offset = (offset - 1) & hashmask;
        }
        if (k != null) {
            return  values[offset];
        }
        else {
            // Add the conversion to the cache
            k = new char[length];
            System.arraycopy(ch, start, k, 0, length);
            String v = new String(k).intern();
            keys[offset] = k;
            values[offset] = v;
            numEntries++;
            return  v;
        }
    }

    private void rehash () {
        int newlength = keys.length << 1;
        char[][] newkeys = new char[newlength][];
        String[] newvalues = new String[newlength];
        int newhashmask = newlength - 1;
        for (int i = 0; i < keys.length; i++) {
            char[] k = keys[i];
            String v = values[i];
            if (k != null) {
                int newoffset = hashKey(k, 0, k.length) & newhashmask;
                char[] newk = null;
                while ((newk = newkeys[newoffset]) != null && !keysAreEqual(newk,
                        0, newk.length, k, 0, k.length)) {
                    newoffset = (newoffset - 1) & newhashmask;
                }
                newkeys[newoffset] = k;
                newvalues[newoffset] = v;
            }
        }
        keys = newkeys;
        values = newvalues;
        maxEntries = (int)(newlength*loadFactor);
        hashmask = newhashmask;
    }

    public void clearCache () {
        for (int i = 0; i < keys.length; i++) {
            keys[i] = null;
            values[i] = null;
        }
        numEntries = 0;
    }

    private static final boolean keysAreEqual (char[] a, int astart, int alength,
            char[] b, int bstart, int blength) {
        if (alength != blength) {
            return  false;
        }
        else {
            for (int i = 0; i < alength; i++) {
                if (a[astart + i] != b[bstart + i]) {
                    return  false;
                }
            }
            return  true;
        }
    }

    private static final int hashKey (char ch[], int start, int length) {
        int hash = 0;
        for (int i = 0; i < length; i++) {
            hash = (hash << 5) + ch[start + i];
        }
        return  hash;
    }
}



