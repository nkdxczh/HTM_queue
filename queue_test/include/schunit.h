#ifndef  SCHUNIT_H
#define  SCHUNIT_H

#include <iostream>
#include <mutex>
#include <atomic>
#include <map>
#include <vector>

class SchUnit{
    private:
        std::mutex lock;
        std::atomic<int> count;
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

    count++;

}

void SchUnit::reset(){

    count = 0;

}

void SchUnit::setQueue(int q){

    queue = q;

}

class SchMap{
    private:
        std::unordered_map<unsigned, SchUnit*> map;
        std::mutex creation_lock;

    public:
        SchUnit* get(unsigned key);
        SchUnit* create(unsigned key, int queue);
        std::map<int, std::vector<unsigned>, std::greater<int>>* getOrderedView();
};

SchUnit* SchMap::get(unsigned key){
    std::unordered_map<unsigned,SchUnit*>::const_iterator it = map.find(key);

    if(it == map.end()){
        return NULL;
    }

    else return it->second;
}

SchUnit* SchMap::create(unsigned key, int queue){
    creation_lock.lock();

    auto it = map.find(key);
    if(it != map.end()){
        creation_lock.unlock();
        return it->second;
    }

    SchUnit* unit = new SchUnit(key);
    unit->setQueue(queue);

    map.insert({key,unit});

    creation_lock.unlock();

    return unit;
}

std::map<int, std::vector<unsigned>, std::greater<int>>* SchMap::getOrderedView(){
    std::map<int, std::vector<unsigned>, std::greater<int>>* res = new std::map<int, std::vector<unsigned>, std::greater<int>>();

    for(auto it = map.begin(); it != map.end(); ++it )
    {
        int key = it->second->getCount();
        unsigned val = it->first;
        auto target = res->find(key);
        if(target == res->end()){
            std::vector<unsigned> newv;
            newv.push_back(val);
            res->insert({key, newv});
        }
        else{
            target->second.push_back(val);
        }
    }

    return res;
}

#endif
