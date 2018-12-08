//
// inverted index main class definition
// InvertedIndex is the manager class of inverted index
// version: 1.0 
// Copyright (C) 2018 James Wei (weijianlhp@163.com). All rights reserved
//

#ifndef CLORIS_CLORISEARCH_H_
#define CLORIS_CLORISEARCH_H_

namespace cloris {

class InvertedIndex {
public:
    InvertedIndex();
    ~InvertedIndex();

    bool Init(const IndexSchema& schema);
    Build();
    bool Add(DNF *dnf, int docid, bool is_incremental);
    bool Update(DNF *dnf, int docid);
    bool Del(int docid);
    std::vector<int> Search(const Query& query, int limit);
private:
    vector<std::string> schemas_; // age, sex, city...
    // 10 mean the max -- is 10
    TermTable* term_;
    // TermTable term_[10]; { "sex" -- GeneralIndexer, "age" -- SectionIndexer, "net" -- GeneralIndexer, "location" -- GeoHashIndexer }
};

} // namespace cloris

#endif // CLORIS_CLORISEARCH_H_
