#ifndef KV_DB_KVDB_H_
#define KV_DB_KVDB_H_

#include <iostream>
#include <string>

#include "Options.h"

using namespace std;

namespace kvdb {

class KvdbDS;

class DB {
public:
    static bool CreateDB(string filename, Options opts = Options());
    static bool OpenDB(string filename, DB** db, Options opts = Options());

    virtual ~DB();

    bool Insert(const char* key, uint32_t key_len, const char* data,
                uint16_t length);
    bool Delete(const char* key, uint32_t key_len);
    bool Get(const char* key, uint32_t key_len, string &data);

    void Do_GC();

private:
    DB();
    DB(const DB &);
    DB& operator=(const DB &);

    string fileName_;
    KvdbDS *kvdb_;
    static DB *instance_;
};

} // namespace kvdb

#endif //KV_DB_KVDB_H_
