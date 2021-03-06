
// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "String.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================

// Sets the const static maximum size to 100 (without counting '\0')	
const size_t String::max_size_=100;

// ===========================================================================
//                                Constructors
// ===========================================================================

// Default constructor
String::String() {

	size_ = 0;
	capacity_ = 0;
	tab_ = new char[capacity_ + 1];
	tab_[0] = '\0';
}

// Copy constructor - constructs a copy of str.
String::String(const String& str){
	
	size_ = str.size_ ;
	capacity_ = str.capacity_;
	tab_ = new char[capacity_ + 1];
	for(size_t i = 0; i<=size_; i++){
		tab_[i] = str.tab_[i];
	}
	
}

// Copies the null-terminated character sequence (C-string) pointed by s.
// First, counting the number of characters in the string put in argument
// If the string put into argument is longer than the max_size_ : 
// printing error message and creating a default string
// Else, doing the copy of the string
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

// Taking a single character in argument
// Replaces the contents with a copy of str. 
// If *this and str are the same object, this function has no effect.
String& String::operator=(char c){
  
	bool equal = false;
	if(tab_[0] == c){

    //Checks if the two strings are not already equal
    if (size_ == 1 && capacity_ == 1){
      equal = true;
    }
    
//If they are not, it replaces the content with the character.

    else{
      this->resize(1);
      capacity_ = 1;
    }
	}
	else{
    this->resize(1);
    capacity_ = 1;
    tab_[0] = c;
  }
  
	if (equal == true){
		printf("The two strings are already equal.\n");
	}
  
	return *this;
}

// Replaces the content with a copy of str. 
// If *this and str are the same object, this function has no effect.
String& String::operator=(const String& str){
	
	//Checks if the two strings are not already equal
	
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
	
	//If they are not, it replaces the content with a copy of str.
	
	if(equal==false){
		size_ = str.size_;
		capacity_ = str.capacity_;
		delete[] tab_;
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


// Replaces the content with a copy of s. 
// If *this and s contain the same object, this function has no effect.
String& String::operator=(const char* s){

//Checks if the string and the char* are not equal 
	bool equal = true;
	size_t sizeCountr = 0;
  for (size_t i = 0 ; s[i] != '\0' ; i++){
    sizeCountr ++;
  }
	if(this->size_ != sizeCountr){
		equal = false;
	}
	else{
		int i = 0;
		while(s[i]!= '\0'){
			if(s[i]!=this->tab_[i]){
				equal = false;
			}
			i++;
		}
	}

//If they are not, it replaces the content with a copy of s.

	if(equal==false){
			size_ = sizeCountr;
			capacity_ = sizeCountr;
			delete[] tab_;
			tab_ = new char[capacity_ + 1];
			for(size_t i = 0; i<size_; i++){
				tab_[i] = s[i];
			}
		}
		
	else{
		printf("The string and the char* are already equal.\n"); 
	}
	return *this;
}

// ===========================================================================
//                                 Destructor
// ===========================================================================

// Destructor - deleting the table created before and printing a message
// to validate the destruction
String::~String() {
	delete [] tab_;
	tab_ = nullptr;
	printf("Protocol order 62 executed : String no longer operational.\n");
}

// ===========================================================================
//                               Public Methods
// ===========================================================================


// ============================= Operators ===================================


// ============================= Getters ===================================

// Getter of the capacity of the string
size_t String::capacity() const{
	return capacity_;
}

// Getter of the size of the string
size_t String::size() const{
	return size_;
}

// Getter of the length (=size) of the string
size_t String::length() const{
	return size_;
}

// Getter of the maximum size of the string
size_t String::max_size() const{
	return max_size_;
}

// Getter of the tab_
// Returns a pointer to an array containing a null-terminated sequence 
// of characters representing the current value of the string object
const char* String::c_str(){
	return tab_;
}

//============================= Setters ====================================

// Erases the contents of the string, which becomes an empty string
// (length of 0 characters). Doesn't modify the capacity
void String::clear(){
	size_ = 0;
	tab_[0] = '\0';
}

// Request a change in capacity
// if n < capacity : let the original capacity
void String::reserve(size_t n){

	if(n > capacity_){
		if(n > max_size_){
			printf("You aren't allowed to reserve more than %d "
				"characters. \n",(int)(max_size_));
		} 
		else {
			char* data = new char[n+1];
			for(size_t i = 0; i < size_ + 1; i++){
				data[i] = tab_[i];
			}
			delete [] tab_;
			tab_ = new char[n+1];
			capacity_=n;
			for(size_t i = 0; i < size_ + 1; i++){
				tab_[i] = data[i];
			} 
			delete [] data;
		}
	} 	
}

// Resizes the string to a length of n characters
// If new size > max_size_ print error message
// If new size < old size 
//  => cutting the old size, and adding '\0' at the end of the new size
// If new size = old size print error message
// If new size > old size => changing the capacity 
//  and adding '/' to extend the old to the new size
void String::resize (size_t n){

  if (n > max_size_){
		printf("You aren't allowed to resize your string with more than %d "
		"characters. Try again.\n",int(max_size_));
  }
  else if (n < size_){
    size_= n;
    tab_[size_] = '\0';
  }
  else if (n == size_){
    printf("You already have a string with %d "
    "characters. Try resizing with another size.\n",int(size_));
  }
  else {
    this->reserve(n);
    
    for(size_t i = size_; i < capacity_; i++){
      tab_[i] = '/';
		}
    size_ = n;
    tab_[size_] = '\0';
    printf("You didn't specify the type of character you wanted, so I "
    "added: '/' to extend your string to the size you chose.\n");
  }
  
}

// Resizes the string to a length of n characters
// If new size > max_size_ print error message
// If new size < old size 
//  => cutting the old size, and adding '\0' at the end of the new size
// If new size = old size print error message
// If new size > old size => changing the capacity 
//  and adding the character in arg. to extend the old to the new size
void String::resize (size_t n, char c){

  if (n > max_size_){
		printf("You aren't allowed to resize your string with more than %d "
		"characters. Try again.\n",int(max_size_));
  }
  else if (n < size_){
    size_= n;
    tab_[size_] = '\0';
  }
  else if (n == size_){
    printf("You already have a string with %d "
    "characters. Try resizing with another size.\n",int(size_));
  }
  else {
    this->reserve(n);

    for(size_t i = size_; i < capacity_; i++){
      tab_[i] = c;
		}
    size_ = n;
    tab_[size_] = '\0';
  }
}

// Other

// Test if string is empty (==0 or not)
// This will not modify anything, returning only True or False
bool String::empty(){
	if(size_==0){
		return true;
	} 
	else {
		return false;
	}
}

// ===========================================================================
//                              Protected Methods
// ===========================================================================

// ===========================================================================
//                              External Methods
// ===========================================================================

String operator+(const String& lhs, char rhs){
  size_t newsize = lhs.size() + 1;
  if( newsize < lhs.max_size_ ){
		String result = String(lhs);
		result.resize(newsize,rhs);
		return result;
	}
	else{
		printf("Not allowed to perform this operation because you are going"
		" beyond the maximum size allowed! The result given is the null string.");
		return String();
	}
}


// Arguments taken : const String& a,const String& b
// Concatenating strings 
// Returns a newly constructed string object 
String operator+(const String& a,const String& b){
	size_t sizeCountr = a.size() + b.size();
  String newString = String();
  if (sizeCountr > newString.max_size()){
    printf("You aren't allowed to concatenate your strings with more"
    " than %d characters in total. Default string created "
    "\n",int(newString.max_size()));
  }
  else {
		newString.reserve(sizeCountr);
    for(size_t i = 0; i < a.size(); i++){
      newString.tab_[i] = a.tab_[i];	
    }
    for(size_t i = a.size(); i<sizeCountr; i++){
      newString.tab_[i] = b.tab_[i-a.size()];		
    }
    newString.size_ = sizeCountr;
    newString.tab_[newString.size()]='\0';
	}	
	return newString;
		
  
	
}

// Arguments taken : const String& slhs,const char* srhs
// Concatenating strings max_size_
// Returns a newly constructed string object 
String operator+(const String& slhs,const char* srhs){ 
  
  size_t sizeCountr = 0;
  for (size_t i = 0 ; srhs[i] != '\0' ; i++){
    sizeCountr ++;
  }
  String newString = String();
  
  if (slhs.size() + sizeCountr > newString.max_size()){
    printf("You aren't allowed to concatenate your strings with more"
    " than %d characters in total. Default string created "
    "\n",int(newString.max_size()));
  }
	else {
		newString.reserve(slhs.size() + sizeCountr);
    for(size_t i = 0; i < slhs.size(); i++){
      newString.tab_[i] = slhs.tab_[i];		
    }
    for(size_t i = slhs.size(); i < slhs.size() + sizeCountr; i++){
      newString.tab_[i] = srhs[i-slhs.size()];		
    }
    newString.size_ = slhs.size() + sizeCountr;
    newString.tab_[newString.size()]='\0';
	}	
	return newString;
}
