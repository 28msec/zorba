/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "util/uuid/sysdep.h"
#include "util/uuid/uuid.h"

namespace zorba {

/* various forward declarations */
static int read_state(xs_short *clockseq, xs_unsignedLong *timestamp,
    uuid_node_t *node);
static void write_state(xs_short clockseq, xs_unsignedLong timestamp,
    uuid_node_t node);
static void format_uuid_v1(uuid_t *uuid, xs_short clockseq,
    xs_unsignedLong timestamp, uuid_node_t node);
static void get_current_time(xs_unsignedLong *timestamp);
static xs_short true_random(void);

int uuid_create(uuid_t *uuid)
{
  xs_unsignedLong timestamp, last_time;
  xs_short clockseq;
  uuid_node_t node;
  memset(&node, 0, sizeof(uuid_node_t));
  uuid_node_t last_node;
  memset(&last_node, 0, sizeof(uuid_node_t));
  int f;

  //acquire system-wide lock so we're alone
  LOCK;
  //get time, node ID, saved state from non-volatile storage
  get_current_time(&timestamp);
//   get_ieee_node_identifier(&node);
  f = read_state(&clockseq, &last_time, &last_node);

  //if no NV state, or if clock went backwards, or node ID
  //changed (e.g., new network card) change clockseq
  if (!f || memcmp(&node, &last_node, sizeof node))
    clockseq = true_random();
  else if (timestamp < last_time)
    clockseq++;

  //save the state for next time
  write_state(clockseq, timestamp, node);

  UNLOCK;

  //stuff fields into the UUID
  format_uuid_v1(uuid, clockseq, timestamp, node);
  return 1;
}

/* format_uuid_v1 -- make a UUID from the timestamp, clockseq,
                     and node ID */
void format_uuid_v1(uuid_t* uuid, xs_short clock_seq,
                    xs_unsignedLong timestamp, uuid_node_t node)
{
  //Construct a version 1 uuid with the information we've gathered plus a few constants.
  uuid->time_low = (xs_unsignedInt)(timestamp & 0xFFFFFFFF);
  uuid->time_mid = (xs_unsignedShort)((timestamp >> 32) & 0xFFFF);
  uuid->time_hi_and_version =(xs_unsignedShort)((timestamp >> 48) & 0x0FFF);
  uuid->time_hi_and_version |= (1 << 12);
  uuid->clock_seq_low = clock_seq & 0xFF;
  uuid->clock_seq_hi_and_reserved = (clock_seq & 0x3F00) >> 8;
  uuid->clock_seq_hi_and_reserved |= 0x80;
  memcpy(&uuid->node, &node, sizeof uuid->node);
}

/* data type for UUID generator persistent state */
typedef struct {
  xs_unsignedLong ts;   // saved timestamp
  uuid_node_t     node; // saved node ID
  xs_short        cs;   // saved clock sequence
} uuid_state;

static uuid_state st;

//read_state -- read UUID generator state from non-volatile store
int read_state(xs_short *clockseq, xs_unsignedLong *timestamp,
               uuid_node_t *node)
{
  static int inited = 0;
  FILE *fp = 0;

  //only need to read state once per boot
  if (!inited) {
#ifdef WIN32
    errno_t err = fopen_s( &fp, "state", "rb");
    if ( err != 0)
      return 0;
#else
    fp = fopen("state", "rb");
    if (fp == NULL)
      return 0;
#endif

    size_t lReadLength = fread(&st, sizeof st, 1, fp);
    fclose(fp);
    if (lReadLength == 0)
      return 0;
    inited = 1;
  }
  *clockseq = st.cs;
  *timestamp = st.ts;
  *node = st.node;
  return 1;
}

// write_state -- save UUID generator state back to non-volatile storage
void write_state(xs_short clockseq, xs_unsignedLong timestamp,
                 uuid_node_t node)
{
  volatile static bool inited = false;
  static xs_unsignedLong next_save;
  FILE* fp = 0;

  if (!inited) {
    next_save = timestamp;
    inited = 1;
  }

  //always save state to volatile shared state
  st.cs = clockseq;
  st.ts = timestamp;
  st.node = node;
  if (timestamp >= next_save) {
#ifdef WIN32
    errno_t err = fopen_s( &fp, "state", "wb");
    if ( err != 0)
      return ;
#else
    fp = fopen("state", "wb");
    if (fp == NULL)
      return ;
#endif
    fwrite(&st, sizeof st, 1, fp);
    fclose(fp);
    //schedule next save for 10 seconds from now
    next_save = timestamp + (10 * 10 * 1000 * 1000);
  }
}

// get-current_time -- get time as 60-bit 100ns ticks since UUID epoch.
// Compensate for the fact that real clock resolution is less than 100ns.
void get_current_time(xs_unsignedLong *timestamp)
{
  static int inited = 0;
  static xs_unsignedLong time_last;
  static xs_short uuids_this_tick;
  xs_unsignedLong time_now;

  if (!inited) {
    get_system_time(&time_now);
    uuids_this_tick = UUIDS_PER_TICK;
    inited = 1;
  }

  for ( ; ; ) {
    get_system_time(&time_now);

    //if clock reading changed since last UUID generated
    if (time_last != time_now) {
      //reset count of uuids gen'd with this clock reading
      uuids_this_tick = 0;
      time_last = time_now;
      break;
    }
    if (uuids_this_tick < UUIDS_PER_TICK) {
      uuids_this_tick++;
      break;
    }
  //going too fast for our clock; spin
  }
  // add the count of uuids to low order bits of the clock reading
  *timestamp = time_now + uuids_this_tick;
}

// true_random -- this does not generate a crypto-quality random number.
static xs_short true_random(void)
{
  static int inited = 0;
  xs_unsignedLong time_now;

  if (!inited) {
    get_system_time(&time_now);
    time_now = time_now / UUIDS_PER_TICK;
    srand((unsigned int)
          (((time_now >> 32) ^ time_now) & 0xffffffff));
    inited = 1;
  }

  return rand();
}

uuid_t NameSpace_DNS = { // 6ba7b810-9dad-11d1-80b4-00c04fd430c8
  0x6ba7b810,
  0x9dad,
  0x11d1,
  0x80,
  0xb4,
  {
    0x00, (unsigned char)0xc0,
    0x4f, (unsigned char)0xd4,
    0x30, (unsigned char)0xc8
  }
};

/* uuidToString -- transform a UUID to a string*/
zstring uuidToString(const uuid_t& u)
{
  char lBuffer[174];
  sprintf(lBuffer, "%8.8x-%4.4x-%4.4x-%2.2x%2.2x-9300a64ac3cd", u.time_low, u.time_mid,
          u.time_hi_and_version, u.clock_seq_hi_and_reserved,
          u.clock_seq_low);

  zstring lResult = lBuffer;
  return lResult;
}

/* uuidToString -- transform a UUID to a uri*/
zstring uuidToURI(const uuid_t& u)
{
  char lBuffer[200];
  sprintf(lBuffer, "uuid:%8.8x-%4.4x-%4.4x-%2.2x%2.2x-9300a64ac3cd", u.time_low, u.time_mid,
          u.time_hi_and_version, u.clock_seq_hi_and_reserved,
          u.clock_seq_low);

  zstring lResult = lBuffer;
  return lResult;
}

/*
//This appendix lists the name space IDs for some potentially
//interesting namespaces, as initialized C structures and in the
//string representation defined above.

// Name string is a URL
uuid_t NameSpace_URL = { // 6ba7b811-9dad-11d1-80b4-00c04fd430c8
  0x6ba7b811,
  0x9dad,
  0x11d1,
  0x80,
  0xb4,
  {0x00, 0xc0, 0x4f, 0xd4, 0x30, 0xc8}
};

// Name string is an ISO OID
uuid_t NameSpace_OID = { // 6ba7b812-9dad-11d1-80b4-00c04fd430c8
  0x6ba7b812,
  0x9dad,
  0x11d1,
  0x80,
  0xb4,
  {0x00, 0xc0, 0x4f, 0xd4, 0x30, 0xc8}
};

// Name string is an X.500 DN (in DER or a text output format)
uuid_t NameSpace_X500 = { // 6ba7b814-9dad-11d1-80b4-00c04fd430c8
  0x6ba7b814,
  0x9dad,
  0x11d1,
  0x80,
  0xb4,
  {0x00, 0xc0, 0x4f, 0xd4, 0x30, 0xc8}
};
*/
}
/* vim:set et sw=2 ts=2: */
