//$Id$

class test_impl :public test
{
 public:
  virtual void bar (CORBA::VoidData something)
    ACE_THROW_SPEC ((CORBA::SystemException))

  {
    ACE_DEBUG ((LM_DEBUG,
		"%d\n",
		(int*)something));
  }
};

