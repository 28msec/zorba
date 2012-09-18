
#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include <zorba/util/time.h>

#include "zorbautils/hashmap.h"
#include "util/hashmap32.h"
#include "util/hashmap.h"
#include "util/unordered_map.h"


namespace zorba {

namespace UnitTests {


class IntCompFunc
{
public:
  static bool equal(uint64_t k1, uint64_t k2) 
  {
    return k1 == k2;
  }

  static uint32_t hash(uint64_t key)
  {
#if 1
    return key;
#else
    char buf[9];
    buf[0] = (unsigned char)(key>>56);
    buf[1] = (unsigned char)(key>>48);
    buf[2] = (unsigned char)(key>>40);
    buf[3] = (unsigned char)(key>>32);
    buf[4] = (unsigned char)(key>>24);
    buf[5] = (unsigned char)(key>>16);
    buf[6] = (unsigned char)(key>>8 );
    buf[7] = (unsigned char)(key    );
    buf[8] = 0;
    return (uint32_t)hashfun::h64((void*)buf,8,FNV_64_INIT);
#endif
  }
};


class StrCompFunc
{
public:
  static bool equal(const zstring& k1, const zstring& k2) 
  {
    return k1 == k2;
  }

  static uint32_t hash(const zstring& key)
  { 
    return hashfun::h32(key.c_str(), FNV_32_INIT);
  }
};


int test_hashmaps(int argc, char* argv[])
{
  if (argc < 4)
    return 1;

  int test_id = atoi(argv[1]);

  double load_factor = atof(argv[2]);

  int num = atoi(argv[3]);

  uint64_t* int_buf = new uint64_t[num];

  for (int i = 0; i < num; ++i)
  {
    int_buf[i] = rand() % num;
  }

  zstring* str_buf = new zstring[num];

  for (int i = 0; i < num; ++i)
  {
    char tmp[20];
    sprintf(tmp, "%d", rand() % num);
    str_buf[i] = tmp;

    //std::cout << str_buf[i] << std::endl;
  }


  HashMap<uint64_t, int, IntCompFunc> map1(1024, false);
  HashMap<zstring, int, StrCompFunc> map2(1024, false);

  std::unordered_map<uint64_t, int> map3(1024);
  std::unordered_map<zstring, int> map4(1024);

  hash64map<int> map5(1024, load_factor);
  hashmap<zstring, int> map6(1024, load_factor);

  map1.set_load_factor(load_factor);
  map2.set_load_factor(load_factor);

  if (test_id == 1)
  {
    zorba::time::walltime startTime;
    zorba::time::get_current_walltime(startTime);

    for (int i = 0; i < num; ++i)
    {
      uint64_t key = int_buf[i];
      int value = 1;
      (void)map1.insert(key, value);
    }
    
    zorba::time::walltime stopTime;
    time::get_current_walltime(stopTime);

    double time = time::get_walltime_elapsed(startTime, stopTime);  

    std::cout << "Load factor = " << load_factor << std::endl
              << "Num numeric insertions = " << num << std::endl
              << "HashMap entries = " << map1.size() << std::endl
              << "HashMap capacity = " << map1.capacity() << std::endl
              << "HashMap colisions = " << map1.collisions() << std::endl
              << "Time = " << time << std::endl;
  }
  else if (test_id == 2)
  {
    zorba::time::walltime startTime;
    zorba::time::get_current_walltime(startTime);

    for (int i = 0; i < num; ++i)
    {
      zstring key = str_buf[i];
      int value = 1;
      (void)map2.insert(key, value);
    }

    zorba::time::walltime stopTime;
    time::get_current_walltime(stopTime);

    double time = time::get_walltime_elapsed(startTime, stopTime);  

    std::cout << "Load factor = " << load_factor << std::endl
              << "Num zstring insertions = " << num << std::endl
              << "HashMap entries = " << map2.size() << std::endl
              << "HashMap capacity = " << map2.capacity() << std::endl
              << "Time = " << time << std::endl;
  }
  else if (test_id == 3)
  {
    zorba::time::walltime startTime;
    zorba::time::get_current_walltime(startTime);

    for (int i = 0; i < num; ++i)
    {
      uint64_t key = int_buf[i];
      int value = 1;
      (void)map3.insert(std::pair<uint64_t, int>(key, value));
    }
    
    zorba::time::walltime stopTime;
    time::get_current_walltime(stopTime);

    double time = time::get_walltime_elapsed(startTime, stopTime);  

    std::cout << "Load factor = " << load_factor << std::endl
              << "Num numeric insertions = " << num << std::endl
              << "UnorderedMap entries = " << map3.size() << std::endl
              << "UnorderedMap buckets = " << map3.bucket_count() << std::endl
              << "Time = " << time << std::endl;
  }
  else if (test_id == 4)
  {
    zorba::time::walltime startTime;
    zorba::time::get_current_walltime(startTime);

    for (int i = 0; i < num; ++i)
    {
      zstring key = str_buf[i];
      int value = 1;
      (void)map4.insert(std::pair<zstring, int>(key, value));
    }

    zorba::time::walltime stopTime;
    time::get_current_walltime(stopTime);

    double time = time::get_walltime_elapsed(startTime, stopTime);  

    std::cout << "Load factor = " << load_factor << std::endl
              << "Num zstring insertions = " << num << std::endl
              << "HashMap entries = " << map4.size() << std::endl
              << "HashMap capacity = " << map4.bucket_count() << std::endl
              << "Time = " << time << std::endl;
  }
  else if (test_id == 5)
  {
    zorba::time::walltime startTime;
    zorba::time::get_current_walltime(startTime);

    for (int i = 0; i < num; ++i)
    {
      uint64_t key = int_buf[i];
      int value = 1;
      (void)map5.put_unsync(key, value);
    }

    zorba::time::walltime stopTime;
    time::get_current_walltime(stopTime);

    double time = time::get_walltime_elapsed(startTime, stopTime);  

    std::cout << "Load factor = " << load_factor << std::endl
              << "Num numeric insertions = " << num << std::endl
              << "hashmap entries = " << map5.size() << std::endl
              << "Time = " << time << std::endl;
  }
  else if (test_id == 6)
  {
    zorba::time::walltime startTime;
    zorba::time::get_current_walltime(startTime);

    for (int i = 0; i < num; ++i)
    {
      zstring key = str_buf[i];
      int value = 1;
      (void)map6.put(key, value, false);
    }

    zorba::time::walltime stopTime;
    time::get_current_walltime(stopTime);

    double time = time::get_walltime_elapsed(startTime, stopTime);  

    std::cout << "Load factor = " << load_factor << std::endl
              << "Num zstring insertions = " << num << std::endl
              << "hashmap entries = " << map6.size() << std::endl
              << "Time = " << time << std::endl;
  }
  else
  {
    std::cout << "Invalid test id" << std::endl;
    return 2;
  }

  return 0;
}


}
}
