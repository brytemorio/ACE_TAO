
/* -*- c++ -*- */
//=============================================================================
/**
 *  @file    be_mirror_port.h
 *
 *  Extension of class AST_Mirror_Port for C++ code generation.
 *
 *  @author Jeff Parsons
 */
//=============================================================================


#ifndef BE_MIRROR_PORT_H
#define BE_MIRROR_PORT_H

#include "ast_mirror_port.h"

#include "be_extended_port.h"

class be_visitor;

/**
 * Extension of class AST_Mirror_Port for C++ code generation.
 */
class be_mirror_port : public virtual AST_Mirror_Port,
                       public virtual be_extended_port
{
public:
  be_mirror_port (
    UTL_ScopedName *n,
    AST_PortType *porttype_ref);

  virtual ~be_mirror_port ();

  virtual void destroy ();

  virtual int accept (be_visitor *visitor);
};

#endif // BE_MIRROR_PORT_H
