// Generated by gencpp from file face_read/ReadTwoFaces.msg
// DO NOT EDIT!


#ifndef FACE_READ_MESSAGE_READTWOFACES_H
#define FACE_READ_MESSAGE_READTWOFACES_H

#include <ros/service_traits.h>


#include <face_read/ReadTwoFacesRequest.h>
#include <face_read/ReadTwoFacesResponse.h>


namespace face_read
{

struct ReadTwoFaces
{

typedef ReadTwoFacesRequest Request;
typedef ReadTwoFacesResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ReadTwoFaces
} // namespace face_read


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::face_read::ReadTwoFaces > {
  static const char* value()
  {
    return "3c14a0fe7db327aef6da537797c5908f";
  }

  static const char* value(const ::face_read::ReadTwoFaces&) { return value(); }
};

template<>
struct DataType< ::face_read::ReadTwoFaces > {
  static const char* value()
  {
    return "face_read/ReadTwoFaces";
  }

  static const char* value(const ::face_read::ReadTwoFaces&) { return value(); }
};


// service_traits::MD5Sum< ::face_read::ReadTwoFacesRequest> should match
// service_traits::MD5Sum< ::face_read::ReadTwoFaces >
template<>
struct MD5Sum< ::face_read::ReadTwoFacesRequest>
{
  static const char* value()
  {
    return MD5Sum< ::face_read::ReadTwoFaces >::value();
  }
  static const char* value(const ::face_read::ReadTwoFacesRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::face_read::ReadTwoFacesRequest> should match
// service_traits::DataType< ::face_read::ReadTwoFaces >
template<>
struct DataType< ::face_read::ReadTwoFacesRequest>
{
  static const char* value()
  {
    return DataType< ::face_read::ReadTwoFaces >::value();
  }
  static const char* value(const ::face_read::ReadTwoFacesRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::face_read::ReadTwoFacesResponse> should match
// service_traits::MD5Sum< ::face_read::ReadTwoFaces >
template<>
struct MD5Sum< ::face_read::ReadTwoFacesResponse>
{
  static const char* value()
  {
    return MD5Sum< ::face_read::ReadTwoFaces >::value();
  }
  static const char* value(const ::face_read::ReadTwoFacesResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::face_read::ReadTwoFacesResponse> should match
// service_traits::DataType< ::face_read::ReadTwoFaces >
template<>
struct DataType< ::face_read::ReadTwoFacesResponse>
{
  static const char* value()
  {
    return DataType< ::face_read::ReadTwoFaces >::value();
  }
  static const char* value(const ::face_read::ReadTwoFacesResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // FACE_READ_MESSAGE_READTWOFACES_H
