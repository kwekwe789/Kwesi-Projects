#ifndef TLB_H
#define TLB_H

#include <vector>
#include <iostream>
#include <random>

#define DEFAULT_TLB_SIZE 4

class tlb_entry {
int page_;
  int frame_;
  int accessed_;

public:

  tlb_entry();
  tlb_entry(int page, int frame);
  void access(int time);
  std::string to_string();
  void setPage(int page);
  void setFrame(int frame);
  void setAccess(int time);
  int getPage();
  int getFrame();
  int getAccess();
  void setEntry(tlb_entry entry, int index);

};

class TLB {
  private:
	int size_;
	//std::vector<tlb_entry> tlb_;

  public:
	TLB();
	TLB(int size);
	bool contains(int page, int time);
	void print();
	void replaceFIFO(tlb_entry entry, int time);
	void replaceRandom(tlb_entry entry, int time);
	void replaceLRU(tlb_entry entry, int time);
	int get_random(const int min, const int max);
	int filled_;
	void insert(tlb_entry entry, int time);
	tlb_entry * tlb_;
	
};

#endif