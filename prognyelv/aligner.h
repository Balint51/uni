#pragma once
#include <vector>
#include <iostream>

template <typename T>
class aligner
{
public:
	aligner():count_num{ 0 } {  }
	size_t max;
	size_t count_num;
	size_t count() { return count_num; }
	std::vector<std::vector<T>*>vec;
	virtual void align() = 0;
	T filler;
	void add(std::vector<T>& obj)
	{
		count_num++;
		vec.push_back(&obj);
	}
	void set_filler(T value)
	{
		filler = value;
	}
	void findMaxSize()
	{
		max =vec[0]->size();
		for (typename std::vector<std::vector<T>*>::iterator it =vec.begin(); it !=vec.end(); it++)
		{
			if (max < (**it).size())
				max = (**it).size();
		}
	}
};


template <typename T>
class left_aligner : public aligner<T>
{
public:
	void align()
	{
		typename std::vector<std::vector<T>*>::iterator it2 = this->vec.end();
		this->findMaxSize();
		for (typename std::vector<std::vector<T>*>::iterator it = this->vec.begin(); it !=it2; it++)
		{
			if ((**it).size() < this->max)
			{
				for (int i = 0; i < (this->max - (**it).size());i++)
				{
					(**it).push_back(T());
					it = this->vec.begin();
					it2 = this->vec.end();
				}
			}
		}
	}
};

template <typename T>
class center_aligner : public aligner<T>
{
public:
	void align() //center
	{
		this->findMaxSize();
		typename std::vector<std::vector<T>*>::iterator it2 = this->vec.end();
		for (typename std::vector<std::vector<T>*>::iterator it = this->vec.begin(); it != it2; it++)
		{
			if ((**it).size() < this->max)
			{
				size_t temp = this->max - (**it).size();
				for (int i = 0; i < ceil((float)temp/2); i++)
				{
					(**it).insert((**it).begin(), T());
					it = this->vec.begin();
					it2 = this->vec.end();
				}
				for (int i = 0; i < floor((float)temp / 2); i++)
				{
					(**it).push_back(T());
					it = this->vec.begin();
					it2 = this->vec.end();
				}
			}
		}
	}
};

template <typename T>
class right_aligner : public aligner<T>
{
public:
	void align()
	{
		this->findMaxSize();
		typename std::vector<std::vector<T>*>::iterator it2 = this->vec.end();
		for (typename std::vector<std::vector<T>*>::iterator it = this->vec.begin(); it != it2; it++)
		{
			if ((**it).size() < this->max)
			{
				for (int i = 0; i < this->max - (**it).size(); i++)
				{
					(**it).insert((**it).begin(), T());

					it = this->vec.begin();
					it2 = this->vec.end();
				}
			}
		}
	}
};
