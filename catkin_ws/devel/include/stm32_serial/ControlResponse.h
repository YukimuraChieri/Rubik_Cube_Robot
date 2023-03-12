// Generated by gencpp from file stm32_serial/ControlResponse.msg
// DO NOT EDIT!


#ifndef STM32_SERIAL_MESSAGE_CONTROLRESPONSE_H
#define STM32_SERIAL_MESSAGE_CONTROLRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace stm32_serial
{
template <class ContainerAllocator>
struct ControlResponse_
{
  typedef ControlResponse_<ContainerAllocator> Type;

  ControlResponse_()
    : feedback()  {
    }
  ControlResponse_(const ContainerAllocator& _alloc)
    : feedback(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _feedback_type;
  _feedback_type feedback;





  typedef boost::shared_ptr< ::stm32_serial::ControlResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::stm32_serial::ControlResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ControlResponse_

typedef ::stm32_serial::ControlResponse_<std::allocator<void> > ControlResponse;

typedef boost::shared_ptr< ::stm32_serial::ControlResponse > ControlResponsePtr;
typedef boost::shared_ptr< ::stm32_serial::ControlResponse const> ControlResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::stm32_serial::ControlResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::stm32_serial::ControlResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::stm32_serial::ControlResponse_<ContainerAllocator1> & lhs, const ::stm32_serial::ControlResponse_<ContainerAllocator2> & rhs)
{
  return lhs.feedback == rhs.feedback;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::stm32_serial::ControlResponse_<ContainerAllocator1> & lhs, const ::stm32_serial::ControlResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace stm32_serial

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::stm32_serial::ControlResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::stm32_serial::ControlResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::stm32_serial::ControlResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::stm32_serial::ControlResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::stm32_serial::ControlResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::stm32_serial::ControlResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::stm32_serial::ControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c14cdf907e5c7c7fd47292add15660f0";
  }

  static const char* value(const ::stm32_serial::ControlResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc14cdf907e5c7c7fULL;
  static const uint64_t static_value2 = 0xd47292add15660f0ULL;
};

template<class ContainerAllocator>
struct DataType< ::stm32_serial::ControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "stm32_serial/ControlResponse";
  }

  static const char* value(const ::stm32_serial::ControlResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::stm32_serial::ControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string feedback\n"
"\n"
"\n"
;
  }

  static const char* value(const ::stm32_serial::ControlResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::stm32_serial::ControlResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ControlResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::stm32_serial::ControlResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::stm32_serial::ControlResponse_<ContainerAllocator>& v)
  {
    s << indent << "feedback: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // STM32_SERIAL_MESSAGE_CONTROLRESPONSE_H
