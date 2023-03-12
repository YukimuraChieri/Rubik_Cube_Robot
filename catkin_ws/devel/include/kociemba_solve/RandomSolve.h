// Generated by gencpp from file kociemba_solve/RandomSolve.msg
// DO NOT EDIT!


#ifndef KOCIEMBA_SOLVE_MESSAGE_RANDOMSOLVE_H
#define KOCIEMBA_SOLVE_MESSAGE_RANDOMSOLVE_H

#include <ros/service_traits.h>


#include <kociemba_solve/RandomSolveRequest.h>
#include <kociemba_solve/RandomSolveResponse.h>


namespace kociemba_solve
{

struct RandomSolve
{

typedef RandomSolveRequest Request;
typedef RandomSolveResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct RandomSolve
} // namespace kociemba_solve


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::kociemba_solve::RandomSolve > {
  static const char* value()
  {
    return "1e50375af0a44d22e32e9a1b65fd9076";
  }

  static const char* value(const ::kociemba_solve::RandomSolve&) { return value(); }
};

template<>
struct DataType< ::kociemba_solve::RandomSolve > {
  static const char* value()
  {
    return "kociemba_solve/RandomSolve";
  }

  static const char* value(const ::kociemba_solve::RandomSolve&) { return value(); }
};


// service_traits::MD5Sum< ::kociemba_solve::RandomSolveRequest> should match
// service_traits::MD5Sum< ::kociemba_solve::RandomSolve >
template<>
struct MD5Sum< ::kociemba_solve::RandomSolveRequest>
{
  static const char* value()
  {
    return MD5Sum< ::kociemba_solve::RandomSolve >::value();
  }
  static const char* value(const ::kociemba_solve::RandomSolveRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::kociemba_solve::RandomSolveRequest> should match
// service_traits::DataType< ::kociemba_solve::RandomSolve >
template<>
struct DataType< ::kociemba_solve::RandomSolveRequest>
{
  static const char* value()
  {
    return DataType< ::kociemba_solve::RandomSolve >::value();
  }
  static const char* value(const ::kociemba_solve::RandomSolveRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::kociemba_solve::RandomSolveResponse> should match
// service_traits::MD5Sum< ::kociemba_solve::RandomSolve >
template<>
struct MD5Sum< ::kociemba_solve::RandomSolveResponse>
{
  static const char* value()
  {
    return MD5Sum< ::kociemba_solve::RandomSolve >::value();
  }
  static const char* value(const ::kociemba_solve::RandomSolveResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::kociemba_solve::RandomSolveResponse> should match
// service_traits::DataType< ::kociemba_solve::RandomSolve >
template<>
struct DataType< ::kociemba_solve::RandomSolveResponse>
{
  static const char* value()
  {
    return DataType< ::kociemba_solve::RandomSolve >::value();
  }
  static const char* value(const ::kociemba_solve::RandomSolveResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // KOCIEMBA_SOLVE_MESSAGE_RANDOMSOLVE_H
