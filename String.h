
#ifndef STRING_H__
#define STRING_H__
// ===========================================================================
//                                  Includes
// ===========================================================================



class String {
	
public :
  // =========================================================================
  //                               Constructors
  // =========================================================================
	String();
	String(const String&);
	String& operator=(const String&);
  String(const char* str);

  // =========================================================================
  //                                Destructor
  // =========================================================================
	~String();

  // =========================================================================
  //                                  Getters
  // =========================================================================

  // =========================================================================
  //                                  Setters
  // =========================================================================

  // =========================================================================
  //                                 Operators
  // =========================================================================

 
  // =========================================================================
  //                              Public Methods
  // =========================================================================
	size_t size() const;
  size_t length() const;
	void clear();
	const char* c_str();
	size_t capacity();
	bool empty();
	void reserve(size_t n);

protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
	char* tab_;
	size_t size_;  //doesn't include de \0
	size_t capacity_;  //includes de \0
	static const size_t max_size_;	

// ===========================================================================
//                            Getters' definitions
// ===========================================================================


// ===========================================================================
//                            Setters' definitions
// ===========================================================================

// ===========================================================================
//                           Operators' definitions
// ===========================================================================

// ===========================================================================
//                        Inline functions' definition
// ===========================================================================

};
#endif // STRING_H__
