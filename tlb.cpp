#include "tlb.h"


tlb_entry::tlb_entry(): page_(0), frame_(0), accessed_(0) {}
tlb_entry::tlb_entry(int page, int frame): page_(page), frame_(frame), accessed_(0) {}

void tlb_entry::access(int time) { this->accessed_ = time; }

std::string tlb_entry::to_string()
{
	return std::to_string(page_) + ":" + std::to_string(frame_);
}


TLB::TLB()
{
    size_ = DEFAULT_TLB_SIZE;
	filled_=0;
	tlb_ = new tlb_entry[size_];
}

TLB::TLB(int size)
{
    size_ = size;
	/*for (int i=0; i<size_; i++)
		tlb_.push_back(tlb_entry(i, i));*/
}

bool TLB::contains(int page, int time) 
{ 
	//std::cout <<  page << std::endl;
	for(int i=0; i< filled_; i++)
    {
        if(tlb_[i].getPage() == page)
		{
			tlb_[i].setAccess(0);
			for(int m(0); m<(filled_); m++)
			{
				if(m!=i)
				{
					tlb_[m].setAccess(tlb_[m].getAccess()+1);
				}
				else
				{}
			}
			return true;
		}
    }
	return false; 
}

void TLB::print()
{
	std::cout << "TLB size: " << filled_ << std::endl;
	std::cout << "TLB Entries (entry, page, frame):" << std::endl;
    for(int i=0; i< filled_; i++)
    {
        std::cout << "  [" << i << "]: " << tlb_[i].to_string() << std::endl;
    }
}


int TLB::get_random(const int min, const int max) 
{
  static std::random_device dev;
  static std::mt19937 twister(dev());
  static std::uniform_int_distribution<int> dist;

  dist.param(std::uniform_int_distribution<int>::param_type(min, max));
  return dist(twister);
}


void TLB::replaceFIFO(tlb_entry entry, int time) 
{
	tlb_[0].setEntry(tlb_[1],0);
	tlb_[1].setEntry(tlb_[2],1);
	tlb_[2].setEntry(tlb_[3],2);
	tlb_[3].setEntry(entry,3);
}

void TLB::replaceLRU(tlb_entry entry, int time)
{
	int max(0);
	int index(0);
	for(int x(0); x<4; x++)
	{
		if(tlb_[x].getAccess()>max)
		{
			max = tlb_[x].getAccess();
			index = x;
		}
	}
	tlb_[index].setEntry(entry,time);
	for(int m(0); m<(filled_); m++)
	{
		if(m!=index)
		{
			tlb_[m].setAccess(tlb_[m].getAccess()+1);
		}
		else
		{}
	}
}

void TLB::replaceRandom(tlb_entry entry, int time) 
{
	int rand = get_random(0,3);
	tlb_[rand].setEntry(entry,time);
}

void TLB::insert(tlb_entry entry, int time)
{
	tlb_[filled_].setPage(entry.getPage());
	tlb_[filled_].setFrame(entry.getFrame());
	tlb_[filled_].setAccess(0);
	if(filled_>0)
	{
		for(int i(0); i<(filled_-1); i++)
		{
			tlb_[filled_].setAccess(tlb_[filled_].getAccess()+1);
		}
	}
	filled_++;
}

void tlb_entry::setEntry(tlb_entry entry, int index)
{
	setPage(entry.getPage());
	setFrame(entry.getFrame());
	setAccess(entry.getAccess());
}

void tlb_entry::setPage(int page)
{
	page_=page;
}
void tlb_entry::setFrame(int frame)
{
	frame_=frame;
}
void tlb_entry::setAccess(int time)
{
	accessed_ = time;
}

int tlb_entry::getPage()
{
	return page_;
}
int tlb_entry::getFrame()
{
	return frame_;
}
int tlb_entry::getAccess()
{
	return accessed_;
}