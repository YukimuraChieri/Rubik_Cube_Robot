// Generated by gencpp from file face_read/GetParametersResponse.msg
// DO NOT EDIT!


#ifndef FACE_READ_MESSAGE_GETPARAMETERSRESPONSE_H
#define FACE_READ_MESSAGE_GETPARAMETERSRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace face_read
{
template <class ContainerAllocator>
struct GetParametersResponse_
{
  typedef GetParametersResponse_<ContainerAllocator> Type;

  GetParametersResponse_()
    : paras()  {
    }
  GetParametersResponse_(const ContainerAllocator& _alloc)
    : paras(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _paras_type;
  _paras_type paras;





  typedef boost::shared_ptr< ::face_read::GetParametersResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::face_read::GetParametersResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetParametersResponse_

typedef ::face_read::GetParametersResponse_<std::allocator<void> > GetParametersResponse;

typedef boost::shared_ptr< ::face_read::GetParametersResponse > GetParametersResponsePtr;
typedef boost::shared_ptr< ::face_read::GetParametersResponse const> GetParametersResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::face_read::GetParametersResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::face_read::GetParametersResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::face_read::GetParametersResponse_<ContainerAllocator1> & lhs, const ::face_read::GetParametersResponse_<ContainerAllocator2> & rhs)
{
  return lhs.paras == rhs.paras;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::face_read::GetParametersResponse_<ContainerAllocator1> & lhs, const ::face_read::GetParametersResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace face_read

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::face_read::GetParametersResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::face_read::GetParametersResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::face_read::GetParametersResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::face_read::GetParametersResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::face_read::GetParametersResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::face_read::GetParametersResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::face_read::GetParametersResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6485c21672e59e8ec1ecffa78b8b97fc";
  }

  static const char* value(const ::face_read::GetParametersResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6485c21672e59e8eULL;
  static const uint64_t static_value2 = 0xc1ecffa78b8b97fcULL;
};

template<class ContainerAllocator>
struct DataType< ::face_read::GetParametersResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "face_read/GetParametersResponse";
  }

  static const char* value(const ::face_read::GetParametersResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::face_read::GetParametersResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string paras\n"
"\n"
;
  }

  static const char* value(const ::face_read::GetParametersResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::face_read::GetParametersResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.paras);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetParametersResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::face_read::GetParametersResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::face_read::GetParametersResponse_<ContainerAllocator>& v)
  {
    s << indent << "paras: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.paras);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FACE_READ_MESSAGE_GETPARAMETERSRESPONSE_H
