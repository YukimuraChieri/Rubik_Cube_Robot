// Generated by gencpp from file face_read/GetParameters.msg
// DO NOT EDIT!


#ifndef FACE_READ_MESSAGE_GETPARAMETERS_H
#define FACE_READ_MESSAGE_GETPARAMETERS_H

#include <ros/service_traits.h>


#include <face_read/GetParametersRequest.h>
#include <face_read/GetParametersResponse.h>


namespace face_read
{

struct GetParameters
{

typedef GetParametersRequest Request;
typedef GetParametersResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetParameters
} // namespace face_read


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::face_read::GetParameters > {
  static const char* value()
  {
    return "6485c21672e59e8ec1ecffa78b8b97fc";
  }

  static const char* value(const ::face_read::GetParameters&) { return value(); }
};

template<>
struct DataType< ::face_read::GetParameters > {
  static const char* value()
  {
    return "face_read/GetParameters";
  }

  static const char* value(const ::face_read::GetParameters&) { return value(); }
};


// service_traits::MD5Sum< ::face_read::GetParametersRequest> should match
// service_traits::MD5Sum< ::face_read::GetParameters >
template<>
struct MD5Sum< ::face_read::GetParametersRequest>
{
  static const char* value()
  {
    return MD5Sum< ::face_read::GetParameters >::value();
  }
  static const char* value(const ::face_read::GetParametersRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::face_read::GetParametersRequest> should match
// service_traits::DataType< ::face_read::GetParameters >
template<>
struct DataType< ::face_read::GetParametersRequest>
{
  static const char* value()
  {
    return DataType< ::face_read::GetParameters >::value();
  }
  static const char* value(const ::face_read::GetParametersRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::face_read::GetParametersResponse> should match
// service_traits::MD5Sum< ::face_read::GetParameters >
template<>
struct MD5Sum< ::face_read::GetParametersResponse>
{
  static const char* value()
  {
    return MD5Sum< ::face_read::GetParameters >::value();
  }
  static const char* value(const ::face_read::GetParametersResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::face_read::GetParametersResponse> should match
// service_traits::DataType< ::face_read::GetParameters >
template<>
struct DataType< ::face_read::GetParametersResponse>
{
  static const char* value()
  {
    return DataType< ::face_read::GetParameters >::value();
  }
  static const char* value(const ::face_read::GetParametersResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // FACE_READ_MESSAGE_GETPARAMETERS_H
