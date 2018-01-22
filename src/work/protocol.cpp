/******************************
  Program "protocol.m" compiled by "Caching Murphi Release 5.4.9"

  Murphi Last Compiled date: "Jan  9 2018"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9"
#define MURPHI_DATE "Jan  9 2018"
#define PROTOCOL_NAME "protocol"
#define BITS_IN_WORLD 248
#define ALIGN

/********************
  Include
 ********************/
#include "../../include/mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
	return ( s << mu_1_Proc::values[ int(val) - 1 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_Proc (const char *name, int os): mu__byte(1, 1, 1, name, os) {};
  mu_1_Proc (void): mu__byte(1, 1, 1) {};
  mu_1_Proc (int val): mu__byte(1, 1, 1, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_Proc::values[] =
  { "Proc_1",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Home: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Home& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Home& val)
  {
    if (val.defined())
      return ( s << mu_1_Home::values[ int(val) - 2] );
    else return ( s << "Undefined" );
  };

  mu_1_Home (const char *name, int os): mu__byte(2, 2, 1, name, os) {};
  mu_1_Home (void): mu__byte(2, 2, 1) {};
  mu_1_Home (int val): mu__byte(2, 2, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -2]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -2] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_Home::values[] = {"HomeType",NULL };

/*** end of enum declaration ***/
mu_1_Home mu_1_Home_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
	return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
	return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1_Node (void): mu__byte(0, 1, 2) {};
  mu_1_Node (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 2) && (value() <= 2)) return (value() - 2);
    if ((value() >= 1) && (value() <= 1)) return (value() - 0);
  return 0;
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 0) return value(val+2);
    if (val >= 1 && val <= 1) return value(val+0);
  return 0;
  };
  const char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
const char *mu_1_Node::values[] = {"HomeType","Proc_1",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_VCType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_VCType& val) { return mu__byte::operator=((int) val); };
  mu_1_VCType (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_VCType (void): mu__byte(0, 2, 2) {};
  mu_1_VCType (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_VCType mu_1_VCType_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 3] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (const char *name, int os): mu__byte(3, 17, 4, name, os) {};
  mu_1_MessageType (void): mu__byte(3, 17, 4) {};
  mu_1_MessageType (int val): mu__byte(3, 17, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -3]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -3] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MessageType::values[] = {"ReadReq","WriteReq","WBReq","AckPut","AckRead","AckWrite","AckWB","AckData","Fwd_GetS","Fwd_GetM","DataNoReqI","DataResp","Inv","PutS","AckInv",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 1, 2) {};
  mu_1__type_0 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_MessageType mu_mtype;
  mu_1_Node mu_src;
  mu_1_VCType mu_vc;
  mu_1_Node mu_aux;
  mu_1__type_0 mu_cnt;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = CompareWeight(a.mu_aux, b.mu_aux);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cnt, b.mu_cnt);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = Compare(a.mu_aux, b.mu_aux);
    if (w!=0) return w;
    w = Compare(a.mu_cnt, b.mu_cnt);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_vc.MultisetSort();
    mu_aux.MultisetSort();
    mu_cnt.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_vc.print_statistic();
    mu_aux.print_statistic();
    mu_cnt.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_src.clear();
    mu_vc.clear();
    mu_aux.clear();
    mu_cnt.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_src.undefine();
    mu_vc.undefine();
    mu_aux.undefine();
    mu_cnt.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_src.reset();
    mu_vc.reset();
    mu_aux.reset();
    mu_cnt.reset();
 };
  void print() {
    mu_mtype.print();
    mu_src.print();
    mu_vc.print();
    mu_aux.print();
    mu_cnt.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_vc.print_diff(prevstate);
    mu_aux.print_diff(prevstate);
    mu_cnt.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_vc.to_state(thestate);
    mu_aux.to_state(thestate);
    mu_cnt.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_vc.value(from.mu_vc.value());
    mu_aux.value(from.mu_aux.value());
    mu_cnt.value(from.mu_cnt.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_mtype.set_self_2(name, ".mtype", os + 0 ); else mu_mtype.set_self_2(NULL, NULL, 0);
  if (name) mu_src.set_self_2(name, ".src", os + 8 ); else mu_src.set_self_2(NULL, NULL, 0);
  if (name) mu_vc.set_self_2(name, ".vc", os + 16 ); else mu_vc.set_self_2(NULL, NULL, 0);
  if (name) mu_aux.set_self_2(name, ".aux", os + 24 ); else mu_aux.set_self_2(NULL, NULL, 0);
  if (name) mu_cnt.set_self_2(name, ".cnt", os + 32 ); else mu_cnt.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_1: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_1& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_1& val)
  {
    if (val.defined())
      return ( s << mu_1__type_1::values[ int(val) - 18] );
    else return ( s << "Undefined" );
  };

  mu_1__type_1 (const char *name, int os): mu__byte(18, 23, 3, name, os) {};
  mu_1__type_1 (void): mu__byte(18, 23, 3) {};
  mu_1__type_1 (int val): mu__byte(18, 23, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -18]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -18] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1__type_1::values[] = {"HM","HS","HI","HSd","HMa","HMd",NULL };

/*** end of enum declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_2_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_2_id () : mu__byte(0,0,0) {};
  mu_1__type_2_id (int val) : mu__byte(0,0,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_2
{
 public:
  mu_1_Node array[ 1 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 1 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_2 (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_2 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_2 ();
  mu_1_Node& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 0) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    {
        array[0].value(from.array[0].value());
        valid[0].value(from.valid[0].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 1; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 1; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 1; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 1; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 1; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_2_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 1; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 1; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Node &element)
  {
    update_size();
    if (current_size >= 1) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 1; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_2_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Node temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 1; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 1; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 1; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 1; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 8 + os); else array[i].set_self(NULL, 0);
  k = os + i * 8;
  for(i = 0; i < 1; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end multiset declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_HomeState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_1 mu_state;
  mu_1_Node mu_owner;
  mu_1__type_2 mu_sharers;
  mu_1_HomeState ( const char *n, int os ) { set_self(n,os); };
  mu_1_HomeState ( void ) {};

  virtual ~mu_1_HomeState(); 
friend int CompareWeight(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = CompareWeight(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_HomeState& a, mu_1_HomeState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = Compare(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_owner.MultisetSort();
    mu_sharers.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_owner.print_statistic();
    mu_sharers.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_owner.clear();
    mu_sharers.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_owner.undefine();
    mu_sharers.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_owner.reset();
    mu_sharers.reset();
 };
  void print() {
    mu_state.print();
    mu_owner.print();
    mu_sharers.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
    mu_sharers.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_owner.to_state(thestate);
    mu_sharers.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_HomeState& operator= (const mu_1_HomeState& from) {
    mu_state.value(from.mu_state.value());
    mu_owner.value(from.mu_owner.value());
    mu_sharers = from.mu_sharers;
    return *this;
  };
};

  void mu_1_HomeState::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_HomeState::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_HomeState::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_state.set_self_2(name, ".state", os + 0 ); else mu_state.set_self_2(NULL, NULL, 0);
  if (name) mu_owner.set_self_2(name, ".owner", os + 8 ); else mu_owner.set_self_2(NULL, NULL, 0);
  if (name) mu_sharers.set_self_2(name, ".sharers", os + 16 ); else mu_sharers.set_self_2(NULL, NULL, 0);
}

mu_1_HomeState::~mu_1_HomeState()
{
}

/*** end record declaration ***/
mu_1_HomeState mu_1_HomeState_undefined_var;

class mu_1__type_3: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_3& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_3& val)
  {
    if (val.defined())
      return ( s << mu_1__type_3::values[ int(val) - 24] );
    else return ( s << "Undefined" );
  };

  mu_1__type_3 (const char *name, int os): mu__byte(24, 39, 5, name, os) {};
  mu_1__type_3 (void): mu__byte(24, 39, 5) {};
  mu_1__type_3 (int val): mu__byte(24, 39, 5, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -24]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -24] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1__type_3::values[] = {"PM","PS","PI","PIMad","PIMa","PIMd","PISad","PISa","PISd","PSMad","PSMd","PSMa","PMIa","PSIa","PMS","PIIa",NULL };

/*** end of enum declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_3 mu_state;
  mu_1_ProcState ( const char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
  }
  void clear() {
    mu_state.clear();
 };
  void undefine() {
    mu_state.undefine();
 };
  void reset() {
    mu_state.reset();
 };
  void print() {
    mu_state.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_state.value(from.mu_state.value());
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_state.set_self_2(name, ".state", os + 0 ); else mu_state.set_self_2(NULL, NULL, 0);
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_4
{
 public:
  mu_1_ProcState array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_4 (const char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - 1 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: Proc is internally represented from 1 to 1.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_4::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"Proc_1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_5_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_5_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_5_id () : mu__byte(0,1,0) {};
  mu_1__type_5_id (int val) : mu__byte(0,1,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_5
{
 public:
  mu_1_Message array[ 2 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 2 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_5 (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_5 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_5 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 1) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 2; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 2; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 2; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 2; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_5_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 2; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 2; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 2) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 2; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_5_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 2; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 2; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 2; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1__type_5::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 2; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 40 + os); else array[i].set_self(NULL, 0);
  k = os + i * 40;
  for(i = 0; i < 2; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_5::~mu_1__type_5()
{
}
/*** end multiset declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1__type_5 array[ 2 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_6 (const char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1__type_5& operator[] (int index) /* const */
  {
    if ( ( index >= 2 ) && ( index <= 2 ) )
      return array[ index - (2) ];
    if ( ( index >= 1 ) && ( index <= 1 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 2; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<2; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<2; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<2; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 2; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 2; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 2; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 2; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 2; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 2; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"HomeType", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"Proc_1", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_7& val) { return mu__byte::operator=((int) val); };
  mu_1__type_7 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_7 (void): mu__byte(0, 1, 2) {};
  mu_1__type_7 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_8& val) { return mu__byte::operator=((int) val); };
  mu_1__type_8 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_8 (void): mu__byte(0, 1, 2) {};
  mu_1__type_8 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1__type_9: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_9& val) { return mu__byte::operator=((int) val); };
  mu_1__type_9 (const char *name, int os): mu__byte(0, 1, 2, name, os) {};
  mu_1__type_9 (void): mu__byte(0, 1, 2) {};
  mu_1__type_9 (int val): mu__byte(0, 1, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_9 mu_1__type_9_undefined_var;

const int mu_ProcCount = 1;
const int mu_VC0 = 0;
const int mu_VC1 = 1;
const int mu_VC2 = 2;
const int mu_NumVCs = 3;
const int mu_QMax = 2;
const int mu_NetMax = 2;
const int mu_Proc_1 = 1;
const int mu_HomeType = 2;
const int mu_ReadReq = 3;
const int mu_WriteReq = 4;
const int mu_WBReq = 5;
const int mu_AckPut = 6;
const int mu_AckRead = 7;
const int mu_AckWrite = 8;
const int mu_AckWB = 9;
const int mu_AckData = 10;
const int mu_Fwd_GetS = 11;
const int mu_Fwd_GetM = 12;
const int mu_DataNoReqI = 13;
const int mu_DataResp = 14;
const int mu_Inv = 15;
const int mu_PutS = 16;
const int mu_AckInv = 17;
const int mu_HM = 18;
const int mu_HS = 19;
const int mu_HI = 20;
const int mu_HSd = 21;
const int mu_HMa = 22;
const int mu_HMd = 23;
const int mu_PM = 24;
const int mu_PS = 25;
const int mu_PI = 26;
const int mu_PIMad = 27;
const int mu_PIMa = 28;
const int mu_PIMd = 29;
const int mu_PISad = 30;
const int mu_PISa = 31;
const int mu_PISd = 32;
const int mu_PSMad = 33;
const int mu_PSMd = 34;
const int mu_PSMa = 35;
const int mu_PMIa = 36;
const int mu_PSIa = 37;
const int mu_PMS = 38;
const int mu_PIIa = 39;
/*** Variable declaration ***/
mu_1_HomeState mu_HomeNode("HomeNode",0);

/*** Variable declaration ***/
mu_1__type_4 mu_Procs("Procs",32);

/*** Variable declaration ***/
mu_1__type_6 mu_Net("Net",40);

/*** Variable declaration ***/
mu_0_boolean mu_msg_processed("msg_processed",232);

/*** Variable declaration ***/
mu_1__type_7 mu_NumberAck("NumberAck",240);

void mu_Send(const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dst, const mu_1_Node& mu_src, const mu_1_VCType& mu_vc, const mu_1_Node& mu_aux, const mu_1__type_8& mu_cnt)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

/*** begin multisetcount 0 declaration ***/
  int mu__intexpr10 = 0;
  {
  mu_1__type_5_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net[mu_dst].valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr10++;
	}
      if (mu_i == 2-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr10) < (mu_NetMax)) ) Error.Error("Assertion failed: Too many messages");
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_vc.isundefined())
  mu_msg.mu_vc.undefine();
else
  mu_msg.mu_vc = mu_vc;
if (mu_aux.isundefined())
  mu_msg.mu_aux.undefine();
else
  mu_msg.mu_aux = mu_aux;
if (mu_cnt.isundefined())
  mu_msg.mu_cnt.undefine();
else
  mu_msg.mu_cnt = mu_cnt;
mu_Net[mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Node& mu_n)
{
switch ((int) mu_msg.mu_mtype) {
case mu_WBReq:
case mu_ReadReq:
case mu_WriteReq:
mu_msg_processed = mu_false;
break;
default:
Error.Error("Error: Unhandled message type!");
break;
}
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

void mu_AddToSharersList(const mu_1_Node& mu_n)
{
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr11 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr11++;
	}
      if (mu_i == 1-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( (mu__intexpr11) == (0) )
{
mu_HomeNode.mu_sharers.multisetadd(mu_n);
}
};
/*** end procedure declaration ***/

void mu_RemoveFromSharersList(const mu_1_Node& mu_n)
{
/*** end multisetremove 0 declaration ***/
  mu_1__type_2_id mu__idexpr12;
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( (mu_HomeNode.mu_sharers[mu_i]) == (mu_n) ) { mu__idexpr12 = mu_i; mu_HomeNode.mu_sharers.multisetremove(mu__idexpr12); };
	}
      if (mu_i == 1-1) break;
    }
/*** end multisetremove 0 declaration ***/
};
/*** end procedure declaration ***/

void mu_HomeReceive(mu_1_Message& mu_msg)
{
/*** Variable declaration ***/
mu_1__type_9 mu_cnt("cnt",0);

/*** begin multisetcount 2 declaration ***/
  int mu__intexpr13 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr13++;
	}
      if (mu_i == 1-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
mu_cnt = mu__intexpr13;
mu_msg_processed = mu_true;
switch ((int) mu_HomeNode.mu_state) {
case mu_HI:
if ( !((mu_cnt) == (0)) ) Error.Error("Assertion failed: Sharers list non-empty, but line is Invalid");
switch ((int) mu_msg.mu_mtype) {
case mu_ReadReq:
mu_HomeNode.mu_state = mu_HS;
mu_AddToSharersList ( mu_msg.mu_src );
mu_Send ( mu_AckRead, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_src, (int)mu_HomeType, mu_VC2, mu_msg.mu_aux, mu_1__type_8_undefined_var );
break;
case mu_WriteReq:
mu_Send ( mu_AckWrite, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_src, (int)mu_HomeType, mu_VC2, mu_msg.mu_aux, mu_1__type_8_undefined_var );
mu_HomeNode.mu_state = mu_HM;
mu_HomeNode.mu_owner = mu_msg.mu_src;
break;
default:
mu_msg_processed = mu_false;
break;
}
break;
case mu_HM:
if ( !((mu_HomeNode.mu_owner.isundefined()) == (mu_false)) ) Error.Error("Assertion failed: HomeNode has no owner, but line is Modified");
switch ((int) mu_msg.mu_mtype) {
case mu_ReadReq:
mu_Send ( mu_Fwd_GetS, mu_HomeNode.mu_owner, (int)mu_HomeType, mu_VC1, mu_msg.mu_src, mu_1__type_8_undefined_var );
mu_HomeNode.mu_state = mu_HSd;
mu_AddToSharersList ( mu_msg.mu_src );
mu_AddToSharersList ( mu_HomeNode.mu_owner );
mu_Send ( mu_AckRead, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
break;
case mu_WriteReq:
mu_Send ( mu_Fwd_GetM, mu_HomeNode.mu_owner, (int)mu_HomeType, mu_VC1, mu_msg.mu_src, mu_1__type_8_undefined_var );
mu_Send ( mu_AckWrite, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
mu_HomeNode.mu_state = mu_HMd;
break;
case mu_WBReq:
mu_HomeNode.mu_state = mu_HI;
mu_Send ( mu_AckWB, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
break;
default:
mu_msg_processed = mu_false;
break;
}
break;
case mu_HS:
if ( !((mu_cnt) != (0)) ) Error.Error("Assertion failed: sharers list empty, but line is shared");
switch ((int) mu_msg.mu_mtype) {
case mu_PutS:{
mu_RemoveFromSharersList ( mu_msg.mu_src );
mu_Send ( mu_AckPut, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr14 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr14++;
	}
      if (mu_i == 1-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
if ( (mu__intexpr14) == (0) )
{
mu_HomeNode.mu_state = mu_HI;
}
break;}
case mu_ReadReq:
mu_AddToSharersList ( mu_msg.mu_src );
mu_Send ( mu_AckRead, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_src, (int)mu_HomeType, mu_VC2, mu_msg.mu_aux, mu_1__type_8_undefined_var );
break;
case mu_WriteReq:{
mu_HomeNode.mu_state = mu_HMa;
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr15++;
	}
      if (mu_i == 1-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
mu_NumberAck = mu__intexpr15;
mu_HomeNode.mu_owner = mu_msg.mu_src;
{
for(int mu_proc = 1; mu_proc <= 1; mu_proc++) {
mu_RemoveFromSharersList ( (int)mu_proc );
if ( (mu_proc) != (mu_HomeNode.mu_owner) )
{
mu_Send ( mu_Inv, (int)mu_proc, (int)mu_HomeType, mu_VC1, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
}
};
};}
break;
default:
mu_msg_processed = mu_false;
break;
}
break;
case mu_HSd:
if ( !((mu_cnt) != (0)) ) Error.Error("Assertion failed: sharers list empty, but line is shared");
switch ((int) mu_msg.mu_mtype) {
case mu_DataResp:
mu_HomeNode.mu_state = mu_HS;
mu_Send ( mu_AckData, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
case mu_PutS:{
mu_RemoveFromSharersList ( mu_msg.mu_src );
mu_Send ( mu_AckPut, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr16 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr16++;
	}
      if (mu_i == 1-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
if ( (mu__intexpr16) == (0) )
{
mu_HomeNode.mu_state = mu_HI;
}
break;}
default:
mu_msg_processed = mu_false;
break;
}
break;
case mu_HMa:
switch ((int) mu_msg.mu_mtype) {
case mu_AckInv:
mu_NumberAck = (mu_NumberAck) - (1);
if ( (mu_NumberAck) == (0) )
{
mu_HomeNode.mu_state = mu_HM;
mu_Send ( mu_AckWrite, mu_msg.mu_src, (int)mu_HomeType, mu_VC1, mu_msg.mu_aux, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_src, (int)mu_HomeType, mu_VC2, mu_msg.mu_aux, mu_1__type_8_undefined_var );
}
break;
default:
mu_msg_processed = mu_false;
break;
}
break;
case mu_HMd:
switch ((int) mu_msg.mu_mtype) {
case mu_DataResp:
mu_HomeNode.mu_state = mu_HM;
break;
default:
mu_msg_processed = mu_false;
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
};
/*** end procedure declaration ***/

void mu_ProcReceive(mu_1_Message& mu_msg, const mu_1_Proc& mu_p)
{
mu_msg_processed = mu_true;
{
  mu_1__type_3& mu_ps = mu_Procs[mu_p].mu_state;
switch ((int) mu_ps) {
case mu_PI:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
break;
case mu_DataResp:
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PM:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
break;
case mu_Fwd_GetS:
mu_ps = mu_PMS;
mu_Send ( mu_DataResp, (int)mu_HomeType, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_aux, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
case mu_Fwd_GetM:
mu_ps = mu_PMIa;
mu_Send ( mu_DataResp, (int)mu_HomeType, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_aux, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
case mu_DataNoReqI:
mu_ps = mu_PMIa;
mu_Send ( mu_DataResp, (int)mu_HomeType, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PS:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_Send ( mu_AckInv, (int)mu_HomeType, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_ps = mu_PI;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PIMad:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
break;
case mu_DataNoReqI:
mu_msg_processed = mu_false;
break;
case mu_AckWrite:
mu_ps = mu_PIMd;
break;
case mu_DataResp:
mu_ps = mu_PIMa;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PIMa:
switch ((int) mu_msg.mu_mtype) {
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
break;
case mu_DataNoReqI:
mu_msg_processed = mu_false;
break;
case mu_Inv:
break;
case mu_AckWrite:
mu_ps = mu_PM;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PIMd:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
break;
case mu_DataResp:
mu_ps = mu_PM;
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PSMad:
switch ((int) mu_msg.mu_mtype) {
case mu_AckWrite:
mu_ps = mu_PSMd;
break;
case mu_Inv:
mu_ps = mu_PIMad;
mu_Send ( mu_AckInv, (int)mu_HomeType, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
case mu_DataResp:
mu_ps = mu_PSMa;
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
break;
case mu_DataNoReqI:
mu_msg_processed = mu_false;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PSMa:
switch ((int) mu_msg.mu_mtype) {
case mu_AckWrite:
mu_ps = mu_PM;
break;
case mu_Inv:
mu_ps = mu_PIMa;
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
break;
case mu_DataNoReqI:
mu_msg_processed = mu_false;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PSMd:
switch ((int) mu_msg.mu_mtype) {
case mu_DataResp:
mu_ps = mu_PM;
break;
case mu_Inv:
mu_ps = mu_PIMd;
break;
case mu_Fwd_GetS:
mu_msg_processed = mu_false;
break;
case mu_Fwd_GetM:
mu_msg_processed = mu_false;
break;
case mu_DataNoReqI:
mu_msg_processed = mu_false;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PMIa:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
break;
case mu_Fwd_GetS:
mu_ps = mu_PSIa;
mu_Send ( mu_DataResp, (int)mu_HomeType, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_Send ( mu_DataResp, mu_msg.mu_aux, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
case mu_Fwd_GetM:
mu_Send ( mu_DataResp, mu_msg.mu_aux, (int)mu_p, mu_VC2, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
break;
case mu_AckData:
break;
case mu_AckWB:
mu_ps = mu_PI;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PMS:
switch ((int) mu_msg.mu_mtype) {
case mu_AckData:
mu_ps = mu_PS;
break;
case mu_Inv:
mu_msg_processed = mu_false;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PIIa:
switch ((int) mu_msg.mu_mtype) {
case mu_AckWrite:
mu_ps = mu_PI;
break;
case mu_AckRead:
mu_ps = mu_PI;
break;
case mu_AckPut:
mu_ps = mu_PI;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PISad:
switch ((int) mu_msg.mu_mtype) {
case mu_AckRead:
mu_ps = mu_PISd;
break;
case mu_Inv:
mu_msg_processed = mu_false;
break;
case mu_DataResp:
mu_ps = mu_PISa;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PISa:
switch ((int) mu_msg.mu_mtype) {
case mu_AckRead:
mu_ps = mu_PS;
break;
case mu_Inv:
mu_msg_processed = mu_false;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PISd:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_msg_processed = mu_false;
break;
case mu_DataResp:
mu_ps = mu_PS;
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_PSIa:
switch ((int) mu_msg.mu_mtype) {
case mu_AckPut:
mu_ps = mu_PI;
break;
case mu_Inv:
break;
default:
cout << "in ";
mu_ps.print();
cout << ", found unexpected ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_HomeNode.clear();
  mu_Procs.clear();
  mu_Net.clear();
  mu_msg_processed.clear();
  mu_NumberAck.clear();
}
void world_class::undefine()
{
  mu_HomeNode.undefine();
  mu_Procs.undefine();
  mu_Net.undefine();
  mu_msg_processed.undefine();
  mu_NumberAck.undefine();
}
void world_class::reset()
{
  mu_HomeNode.reset();
  mu_Procs.reset();
  mu_Net.reset();
  mu_msg_processed.reset();
  mu_NumberAck.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNode.print();
  mu_Procs.print();
  mu_Net.print();
  mu_msg_processed.print();
  mu_NumberAck.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_HomeNode.print_statistic();
  mu_Procs.print_statistic();
  mu_Net.print_statistic();
  mu_msg_processed.print_statistic();
  mu_NumberAck.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_HomeNode.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
    mu_msg_processed.print_diff(prevstate);
    mu_NumberAck.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_HomeNode.to_state( newstate );
  mu_Procs.to_state( newstate );
  mu_Net.to_state( newstate );
  mu_msg_processed.to_state( newstate );
  mu_NumberAck.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_5_id mu_midx;
    mu_midx.value((r % 2) + 0);
    r = r / 2;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 2);
    r = r / 2;
    return tsprintf("receive, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_5_id mu_midx;
    mu_midx.value((r % 2) + 0);
    r = r / 2;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 2);
    r = r / 2;
  if (!mu_Net[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_5& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
bool mu__boolexpr17;
bool mu__boolexpr18;
  if ((mu_msg.mu_vc) == (mu_VC2)) mu__boolexpr18 = TRUE ;
  else {
bool mu__boolexpr19;
  if (!((mu_msg.mu_vc) == (mu_VC1))) mu__boolexpr19 = FALSE ;
  else {
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr20 = 0;
  {
  mu_1__type_5_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
	{
	  if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr20++;
	}
      if (mu_m == 2-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
  mu__boolexpr19 = ((mu__intexpr20) == (0)) ; 
}
  mu__boolexpr18 = (mu__boolexpr19) ; 
}
  if (mu__boolexpr18) mu__boolexpr17 = TRUE ;
  else {
bool mu__boolexpr21;
bool mu__boolexpr22;
  if (!((mu_msg.mu_vc) == (mu_VC0))) mu__boolexpr22 = FALSE ;
  else {
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr23 = 0;
  {
  mu_1__type_5_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
	{
	  if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr23++;
	}
      if (mu_m == 2-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
  mu__boolexpr22 = ((mu__intexpr23) == (0)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
/*** begin multisetcount 8 declaration ***/
  int mu__intexpr24 = 0;
  {
  mu_1__type_5_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
	{
	  if ( (mu_chan[mu_m].mu_vc) == (mu_VC1) ) mu__intexpr24++;
	}
      if (mu_m == 2-1) break;
    }
  }
/*** end multisetcount 8 declaration ***/
  mu__boolexpr21 = ((mu__intexpr24) == (0)) ; 
}
  mu__boolexpr17 = (mu__boolexpr21) ; 
}
    return mu__boolexpr17;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1__type_5_id mu_midx;
    mu_midx.value((r % 2) + 0);
    r = r / 2;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 2);
    r = r / 2;
    while (what_rule < 4 && mu_midx.value()<2 )
      {
	if ( ( TRUE && mu_Net[mu_n].in(mu_midx) ) ) {
  mu_1__type_5& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
bool mu__boolexpr25;
bool mu__boolexpr26;
  if ((mu_msg.mu_vc) == (mu_VC2)) mu__boolexpr26 = TRUE ;
  else {
bool mu__boolexpr27;
  if (!((mu_msg.mu_vc) == (mu_VC1))) mu__boolexpr27 = FALSE ;
  else {
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr28 = 0;
  {
  mu_1__type_5_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
	{
	  if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr28++;
	}
      if (mu_m == 2-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
  mu__boolexpr27 = ((mu__intexpr28) == (0)) ; 
}
  mu__boolexpr26 = (mu__boolexpr27) ; 
}
  if (mu__boolexpr26) mu__boolexpr25 = TRUE ;
  else {
bool mu__boolexpr29;
bool mu__boolexpr30;
  if (!((mu_msg.mu_vc) == (mu_VC0))) mu__boolexpr30 = FALSE ;
  else {
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr31 = 0;
  {
  mu_1__type_5_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
	{
	  if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr31++;
	}
      if (mu_m == 2-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
  mu__boolexpr30 = ((mu__intexpr31) == (0)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
/*** begin multisetcount 8 declaration ***/
  int mu__intexpr32 = 0;
  {
  mu_1__type_5_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
	{
	  if ( (mu_chan[mu_m].mu_vc) == (mu_VC1) ) mu__intexpr32++;
	}
      if (mu_m == 2-1) break;
    }
  }
/*** end multisetcount 8 declaration ***/
  mu__boolexpr29 = ((mu__intexpr32) == (0)) ; 
}
  mu__boolexpr25 = (mu__boolexpr29) ; 
}
	      if (mu__boolexpr25) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    mu_midx.value((r % 2) + 0);
    r = r / 2;
    mu_n.unionassign(r % 2);
    r = r / 2;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_5_id mu_midx;
    mu_midx.value((r % 2) + 0);
    r = r / 2;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 2);
    r = r / 2;
  mu_1__type_5& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
if ( (mu_n>=2 && mu_n<=2) )
{
mu_HomeReceive ( mu_msg );
if ( mu_msg_processed )
{
mu_chan.multisetremove(mu_midx);
}
}
else
{
mu_ProcReceive ( mu_msg, (int)mu_n );
if ( mu_msg_processed )
{
mu_chan.multisetremove(mu_midx);
}
}
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("evict, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
    return (mu_p.mu_state) == (mu_PS);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
	      if ((mu_p.mu_state) == (mu_PS)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 4;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_PutS, (int)mu_HomeType, (int)mu_n, mu_VC0, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_p.mu_state = mu_PSIa;
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("writeback, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
    return (mu_p.mu_state) == (mu_PM);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5;
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
	      if ((mu_p.mu_state) == (mu_PM)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 5;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_WBReq, (int)mu_HomeType, (int)mu_n, mu_VC0, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_p.mu_state = mu_PMIa;
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("upgrade request, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
    return (mu_p.mu_state) == (mu_PS);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 6;
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 7 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
	      if ((mu_p.mu_state) == (mu_PS)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 6;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_WriteReq, (int)mu_HomeType, (int)mu_n, mu_VC0, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_p.mu_state = mu_PSMad;
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("write request, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
    return (mu_p.mu_state) == (mu_PI);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 7;
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 8 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
	      if ((mu_p.mu_state) == (mu_PI)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 7;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_WriteReq, (int)mu_HomeType, (int)mu_n, mu_VC0, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_p.mu_state = mu_PIMad;
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    return tsprintf("read request, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
    return (mu_p.mu_state) == (mu_PI);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 8;
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    while (what_rule < 9 )
      {
	if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
	      if ((mu_p.mu_state) == (mu_PI)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 8;
    mu_n.value((r % 1) + 1);
    r = r / 1;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 1) + 1);
    r = r / 1;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_ReadReq, (int)mu_HomeType, (int)mu_n, mu_VC0, mu_1_Node_undefined_var, mu_1__type_8_undefined_var );
mu_p.mu_state = mu_PISad;
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<4)
    { R0.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<5)
    { R1.NextRule(what_rule);
      if (what_rule<5) return; }
  if (what_rule>=5 && what_rule<6)
    { R2.NextRule(what_rule);
      if (what_rule<6) return; }
  if (what_rule>=6 && what_rule<7)
    { R3.NextRule(what_rule);
      if (what_rule<7) return; }
  if (what_rule>=7 && what_rule<8)
    { R4.NextRule(what_rule);
      if (what_rule<8) return; }
  if (what_rule>=8 && what_rule<9)
    { R5.NextRule(what_rule);
      if (what_rule<9) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=3) return R0.Condition(r-0);
  if (r>=4 && r<=4) return R1.Condition(r-4);
  if (r>=5 && r<=5) return R2.Condition(r-5);
  if (r>=6 && r<=6) return R3.Condition(r-6);
  if (r>=7 && r<=7) return R4.Condition(r-7);
  if (r>=8 && r<=8) return R5.Condition(r-8);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=3) { R0.Code(r-0); return; } 
  if (r>=4 && r<=4) { R1.Code(r-4); return; } 
  if (r>=5 && r<=5) { R2.Code(r-5); return; } 
  if (r>=6 && r<=6) { R3.Code(r-6); return; } 
  if (r>=7 && r<=7) { R4.Code(r-7); return; } 
  if (r>=8 && r<=8) { R5.Code(r-8); return; } 
}
int Priority(unsigned short r)
{
  if (r<=3) { return R0.Priority(); } 
  if (r>=4 && r<=4) { return R1.Priority(); } 
  if (r>=5 && r<=5) { return R2.Priority(); } 
  if (r>=6 && r<=6) { return R3.Priority(); } 
  if (r>=7 && r<=7) { return R4.Priority(); } 
  if (r>=8 && r<=8) { return R5.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=3) return R0.Name(r-0);
  if (r>=4 && r<=4) return R1.Name(r-4);
  if (r>=5 && r<=5) return R2.Name(r-5);
  if (r>=6 && r<=6) return R3.Name(r-6);
  if (r>=7 && r<=7) return R4.Name(r-7);
  if (r>=8 && r<=8) return R5.Name(r-8);
  return NULL;
}
};
const unsigned numrules = 9;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 9


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
mu_HomeNode.mu_state = mu_HI;
mu_HomeNode.mu_sharers.undefine();
mu_HomeNode.mu_owner.undefine();
{
for(int mu_i = 1; mu_i <= 1; mu_i++) {
mu_Procs[mu_i].mu_state = mu_PI;
};
};
mu_Net.undefine();
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_33() // Invariant "modified w/ empty sharers list"
{
bool mu__boolexpr34;
  if (!((mu_HomeNode.mu_state) == (mu_HM))) mu__boolexpr34 = TRUE ;
  else {
/*** begin multisetcount 9 declaration ***/
  int mu__intexpr35 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_HomeNode.mu_sharers.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr35++;
	}
      if (mu_i == 1-1) break;
    }
  }
/*** end multisetcount 9 declaration ***/
  mu__boolexpr34 = ((mu__intexpr35) == (0)) ; 
}
return mu__boolexpr34;
};

bool mu__condition_36() // Condition for Rule "modified w/ empty sharers list"
{
  return mu__invariant_33( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"modified w/ empty sharers list", &mu__condition_36, NULL, },
};
const unsigned short numinvariants = 1;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
Procs:NoScalarset
msg_processed:NoScalarset
NumberAck:NoScalarset
Net:Complex
HomeNode:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_Procs.MultisetSort();
        mu_msg_processed.MultisetSort();
        mu_NumberAck.MultisetSort();
        mu_Net.MultisetSort();
        mu_HomeNode.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Proc::Permute(PermSet& Perm, int i) {}
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm) {}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Home::Permute(PermSet& Perm, int i) {};
void mu_1_Home::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Home::Canonicalize(PermSet& Perm) {};
void mu_1_Home::SimpleLimit(PermSet& Perm) {};
void mu_1_Home::ArrayLimit(PermSet& Perm) {};
void mu_1_Home::Limit(PermSet& Perm) {};
void mu_1_Home::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_VCType::Permute(PermSet& Perm, int i) {};
void mu_1_VCType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_VCType::Canonicalize(PermSet& Perm) {};
void mu_1_VCType::SimpleLimit(PermSet& Perm) {};
void mu_1_VCType::ArrayLimit(PermSet& Perm) {};
void mu_1_VCType::Limit(PermSet& Perm) {};
void mu_1_VCType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_aux.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_aux.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Node value[1];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[1][1];
  bool goodset_multisetindex[1];
  mu_1_Node temp;

  // compact
  for (i = 0, j = 0; i < 1; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 1; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 1; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {


  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard && while_guard_temp;
    } // end while
  }
}
void mu_1_HomeState::Permute(PermSet& Perm, int i)
{
};
void mu_1_HomeState::SimpleCanonicalize(PermSet& Perm)
{
  mu_owner.SimpleCanonicalize(Perm);
};
void mu_1_HomeState::Canonicalize(PermSet& Perm)
{
};
void mu_1_HomeState::SimpleLimit(PermSet& Perm)
{
  mu_owner.SimpleLimit(Perm);
};
void mu_1_HomeState::ArrayLimit(PermSet& Perm){}
void mu_1_HomeState::Limit(PermSet& Perm)
{
};
void mu_1_HomeState::MultisetLimit(PermSet& Perm)
{
  mu_sharers.MultisetLimit(Perm);
};
void mu_1__type_3::Permute(PermSet& Perm, int i) {};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_3::Canonicalize(PermSet& Perm) {};
void mu_1__type_3::SimpleLimit(PermSet& Perm) {};
void mu_1__type_3::ArrayLimit(PermSet& Perm) {};
void mu_1__type_3::Limit(PermSet& Perm) {};
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm){}
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm){};
void mu_1__type_4::SimpleLimit(PermSet& Perm){}
void mu_1__type_4::ArrayLimit(PermSet& Perm) {}
void mu_1__type_4::Limit(PermSet& Perm){}
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[2];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[2][2];
  bool goodset_multisetindex[2];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 2; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 2; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 2; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {


  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard && while_guard_temp;
    } // end while
  }
}
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<2; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_6::Canonicalize(PermSet& Perm)
{
  for (int j=0; j<2; j++)
    array[j].Canonicalize(Perm);
}
void mu_1__type_6::SimpleLimit(PermSet& Perm){}
void mu_1__type_6::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_5 value[2];
  // limit
  bool exists;
  bool split;
}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{
  for (int j=0; j<2; j++) {
    array[j].MultisetLimit(Perm);
  }
}
void mu_1__type_7::Permute(PermSet& Perm, int i) {};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_7::Canonicalize(PermSet& Perm) {};
void mu_1__type_7::SimpleLimit(PermSet& Perm) {};
void mu_1__type_7::ArrayLimit(PermSet& Perm) {};
void mu_1__type_7::Limit(PermSet& Perm) {};
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i) {};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_8::Canonicalize(PermSet& Perm) {};
void mu_1__type_8::SimpleLimit(PermSet& Perm) {};
void mu_1__type_8::ArrayLimit(PermSet& Perm) {};
void mu_1__type_8::Limit(PermSet& Perm) {};
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_9::Permute(PermSet& Perm, int i) {};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_9::Canonicalize(PermSet& Perm) {};
void mu_1__type_9::SimpleLimit(PermSet& Perm) {};
void mu_1__type_9::ArrayLimit(PermSet& Perm) {};
void mu_1__type_9::Limit(PermSet& Perm) {};
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_msg_processed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_NumberAck.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_NumberAck.MultisetSort();
              mu_Net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
              mu_HomeNode.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_HomeNode.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
          mu_msg_processed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_msg_processed.MultisetSort();
          mu_NumberAck.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_NumberAck.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
          mu_HomeNode.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_HomeNode.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_msg_processed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_NumberAck.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_NumberAck.MultisetSort();
              mu_Net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
              mu_HomeNode.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_HomeNode.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_Procs.MultisetSort();
      mu_msg_processed.MultisetSort();
      mu_NumberAck.MultisetSort();
      mu_Net.MultisetSort();
      mu_HomeNode.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_msg_processed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_msg_processed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_NumberAck.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_NumberAck.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_HomeNode.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_HomeNode.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_HomeNode.SimpleCanonicalize(Perm);

  mu_Net.MultisetSort();

  mu_HomeNode.MultisetSort();

  if (Perm.MoreThanOneRemain()) {
    mu_Net.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.MultisetLimit(Perm);
  }

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_HomeNode.SimpleCanonicalize(Perm);

  mu_Net.MultisetSort();

  mu_HomeNode.MultisetSort();

  if (Perm.MoreThanOneRemain()) {
    mu_Net.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_HomeNode.MultisetLimit(Perm);
  }

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_HomeNode.SimpleCanonicalize(Perm);

  mu_Net.MultisetSort();

  mu_HomeNode.MultisetSort();

};

/********************
  Include
 ********************/
#include "../../include/mu_epilog.hpp"
