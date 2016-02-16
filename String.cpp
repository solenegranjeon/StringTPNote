
// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "String.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

const size_t String::max_size_=100;
// ===========================================================================
//                                Constructors
// ===========================================================================
String::String() {

	size_ = 0;
	capacity_ = 0;
	tab_ = new char[capacity_ + 1];
	tab_[0] = '\0';
}

String::String(const String& str){
	
	size_ = str.size_ ;
	capacity_ = str.capacity_;
	tab_ = new char[capacity_ + 1];
	for(size_t i = 0; i<size_; i++){
		tab_[i] = str.tab_[i];
	}
	
}	

// Replaces the contents with a copy of str. 
// If *this and str are the same object, this function has no effect.
String& String::operator=(const String& str){
	
	bool equal = true;
	if(this->size_ != str.size_ or this->capacity_ != str.capacity_){
		equal = false;
	}
	else{
		int i = 0;
		while(str.tab_[i]!= '\0'){
			if(str.tab_[i]!=this->tab_[i]){
				equal = false;
			}
			i++;
		}
	}
	
	if(equal==false){
		size_ = str.size_;
		capacity_ = str.capacity_;
		tab_ = new char[capacity_ + 1];
		for(size_t i = 0; i<size_; i++){
			tab_[i] = str.tab_[i];
		}
	}
	else{
		printf("The two strings are already equal.\n");
	}
	return *this;
}

String& String::operator+(const String& str){
	size_t sizeTemp=str.size();
	if(size_+sizeTemp>capacity_){
		reserve(size_+sizeTemp+1);
	}
	for(size_t i=size_;i<size_+sizeTemp;i++){
		tab_[i]=str.tab_[i];		
	}
	size_+=sizeTemp;
	tab_[size_+1]='\0';
	return *this;
}

String::String(const char* str){
  
  size_t sizeCount = 0;
  for (size_t i = 0 ; str[i] != '\0' ; i++){
    sizeCount ++;
  }
  
  if (sizeCount <= max_size_){
    size_ = sizeCount ;
    capacity_ = sizeCount ;
    tab_ = new char[capacity_ + 1];
    for(size_t i = 0; i<=size_; i++){
      tab_[i] = str[i];
    }	
  }
  
  else {
    printf("The string you want to put is too long for me, I can't "
      "handle it. So I created a new string with values by default.\n");
    size_ = 0;
    capacity_ = 0;
    tab_ = new char[capacity_+1];
    tab_[0] = '\0';
  }
}	


// ===========================================================================
//                                 Destructor
// ===========================================================================
String::~String() {
	delete [] tab_;
	tab_ = nullptr;
	printf("Protocol order 62 executed : String no longer operational. \n");
}

// ===========================================================================
//                               Public Methods
// ===========================================================================

size_t String::capacity(){
	return capacity_;
}

size_t String::size() const{
	return size_;
}

size_t String::length() const{
	return size_;
}

size_t String::max_size() const{
	return max_size_;
}

void String::clear(){
	size_ = 0;
	tab_[0] = '\0';
}

const char* String::c_str(){
	return tab_;
}

bool String::empty(){
	if(size_==0){
		return true;
	} 
	else {
		return false;
	}
}

void String::reserve(size_t n){
	if(n>capacity_){
		if(n>max_size_){
			printf("You aren't allowed to reserve more than %d "
				"characters. \n",(int)(max_size_));
		} else {
			char* data= new char[n];
			for(size_t i = 0; i<size_ + 1; i++){
				data[i] = tab_[i];
			}
			delete [] tab_;
			tab_ = new char[n]; // Attention, je dirais que c'est +1
			capacity_=n;
			for(size_t i = 0; i<size_ + 1; i++){
				tab_[i] = data[i];
			}
			delete [] data;
		}
	} 	
}

void String::resize (size_t n){
  if (n > max_size_){
		printf("You aren't allowed to resize your string with more than %d "//to or with?
		"characters. \n",int(max_size_));
  }
  else if (n < (size_-1)){
    size_= n;
    tab_[size_] = '\0'; //Is it ok for you if I let the \0 of the
    // previous form? or do I have to remove it?
  }
  else if (n == size_){
    printf("You already have a string with %d "
    "characters. Try resizing with another size.\n",int(size_));
  }
  else {
    char* table = new char[n+1];
		for (size_t i = 0; i < size_ ; i++){
      table[i] = tab_[i];
    }
    delete [] tab_;

    capacity_ = n;
		tab_ = new char[capacity_+1];
    
    for(size_t i = 0; i < size_; i++){
      tab_[i] = table[i];
		}
		delete [] table;
    
    for(size_t i = size_; i < (capacity_+1); i++){
      tab_[i] = '/';
		}
    size_ = n;
    printf("You didn't specify the type of character you wanted, so I "
    "added: / to extend your string to the size you chose.\n");
  }
  
}

void String::resize (size_t n, char c){
  if (n > max_size_){
		printf("You aren't allowed to resize your string with more than %d "//to or with?
		"characters. \n",int(max_size_));
  }
  else if (n < (size_-1)){
    size_= n;
    tab_[size_] = '\0'; //Is it ok for you if I let the \0 of the
    // previous form? or do I have to remove it?
  }
  else if (n == size_){
    printf("You already have a string with %d "
    "characters. Try resizing with another size.\n",int(size_));
  }
  else {
    char* table = new char[n+1];
		for (size_t i = 0; i < size_ ; i++){
      table[i] = tab_[i];
    }
    delete [] tab_;

    capacity_ = n;
		tab_ = new char[capacity_+1];
    
    for(size_t i = 0; i < size_; i++){
      tab_[i] = table[i];
		}
		delete [] table;
    
    for(size_t i = size_; i < (capacity_+1); i++){
      tab_[i] = c;
		}
    size_ = n;
  }
}



// ===========================================================================
//                              Protected Methods
// ===========================================================================

// ===========================================================================
//                              External Methods
// ===========================================================================
