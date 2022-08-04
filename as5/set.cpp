#include "set.h"
#include <iostream>

bool equal(const std::string& s1, const std::string& s2) {
    if (s1.size()!=s2.size()) return false;
    for (size_t i=0; i<s1.size();i++) {
        if (tolower(s1[i])!=tolower(s2[i])) return false;
    }
    return true;
}

size_t hash(const std::string& s) {
    size_t h=0;
    size_t quof=17;
    for (size_t i=s.size()-1; i>=0; i--) {
        h+=tolower(s[i])*quof;
        quof*=17;
        quof%=10000007;
        if (i==0) break;    
    }   
    return h;
}

set::set(const set& s):
bucket_array(new std::list<std::string>[s.bucket_array_size]),
bucket_array_size(s.bucket_array_size),
set_size(s.set_size)
{
    for (size_t i=0; i<bucket_array_size; i++) {
        for (std::string str:s.bucket_array[i]) {
            size_t h=hash(str)%bucket_array_size;
            bucket_array[h].push_back(str);              
        }
    }
}

set& set::operator=(const set& s) {
    if (bucket_array_size!=s.bucket_array_size) {
        delete[] bucket_array;
        bucket_array_size=s.bucket_array_size;
        bucket_array=new std::list<std::string>[bucket_array_size];
    }
    set_size=s.set_size;
    for (size_t i=0; i<bucket_array_size; i++) {
        for (std::string str:s.bucket_array[i]) {
            bucket_array[i]=s.bucket_array[i];
        }
    }
    return *this;
}

set::set(std::initializer_list<std::string> ilist):
bucket_array(new std::list<std::string>[ilist.size()*2]),
bucket_array_size(ilist.size()*2),
set_size(0)
{
    for (auto it:ilist) {
        insert(it);
    }
}

bool set::insert(std::string val) {
    if (loadfactor()>max_load_factor) {
        std::list<std::string>* newarray=new std::list<std::string>[bucket_array_size*2];
        bucket_array_size*=2;
        for (size_t i=0; i<bucket_array_size/2; i++) {
            for (std::string str:bucket_array[i]) {
                size_t h=hash(str)%bucket_array_size;
                newarray[h].push_back(str);              
            }
        }
        delete[] bucket_array;
        bucket_array=newarray;
    }
    size_t h=hash(val)%bucket_array_size;
    if (contains(val)) return false;
    bucket_array[h].push_back(val);
    set_size++;
    return true; 
}
bool set::contains(std::string val) const {
    size_t h=hash(val)%bucket_array_size;
    if (bucket_array[h].size()==0) return false;
    for (std::string str:bucket_array[h]) {
        if (equal(str,val)) return true;
    }
    return false;
}
size_t set::size() const{
    return set_size;
}
bool set::empty() const {
    return size()==0;
}

bool set::remove(std::string val) {
    size_t h=hash(val)%bucket_array_size;
    for(auto p = bucket_array[h].begin(); p != bucket_array[h].end(); ++p) {
        if (equal(*p,val)) {
            bucket_array[h].erase(p);
            set_size--;
            return true;
        }
    }
    return false;
}
void set::clear() {
    set_size=0;
    for (size_t i=0; i<bucket_array_size; i++) {
        bucket_array[i].clear();
    }
}

set::~set() {
    delete[] bucket_array;
}