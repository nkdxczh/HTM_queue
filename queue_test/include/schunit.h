#ifndef  SCHUNIT_H
#define  SCHUNIT_H

#include <iostream>
#include <mutex>

class SchUnit{
    private:
        std::mutex lock;
        int count;
        int queue;

    public:
        SchUnit(int q) : count(0), queue(q){}
        void add();
        void reset();
        void setQueue(int q);

        int getCount(){return count;}
        int getQueue(){return queue;}
};

void SchUnit::add(){
    lock.lock();

    count++;

    lock.unlock();
}

void SchUnit::reset(){
    lock.lock();

    count = 0;

    lock.unlock();
}

void SchUnit::setQueue(int q){
    lock.lock();

    queue = q;

    lock.unlock();
}

class SchMap{
    private:
        std::unordered_map<unsigned, SchUnit*> map;

    public:
        SchUnit* get(unsigned key, int num_q);
};

SchUnit* SchMap::get(unsigned key, int num_q){
      std::unordered_map<unsigned,SchUnit*>::const_iterator it = map.find(key);

      if(it == map.end()){
          SchUnit* unit = new SchUnit(key % num_q);
          
          map.insert({key,unit});

          return unit;
      }

      else return it->second;
}

#endif
