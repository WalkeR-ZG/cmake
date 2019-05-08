#ifndef ROLE_H_
#define ROLE_H_

#define ROLE(role)  get##role()
#define ROLE_PROTO_TYPE(role)  virtual role& ROLE(role) const
#define USE_ROLE(role)  ROLE_PROTO_TYPE(role)  =  0
#define HAS_ROLE(role) USE_ROLE(role)

#define IMPL_ROLE(role)                                       \
ROLE_PROTO_TYPE(role)                                         \
{                                                             \
   return const_cast<role&>(static_cast<const role&>(*this)); \
}

#define IMPL_ROLE_WITH_VAR(role, ptVar)                                       \
ROLE_PROTO_TYPE(role)                                         \
{                                                             \
   return const_cast<role&>(static_cast<const role&>(*ptVar)); \
}

namespace details
{
   struct Role
   {
      virtual ~Role() {}
   };
}
#define DEFINE_ROLE(role)  struct role : ::details::Role

#define ABSTRACT(...) virtual __VA_ARGS__ = 0
#define OVERRIDE(...) virtual __VA_ARGS__

#endif
