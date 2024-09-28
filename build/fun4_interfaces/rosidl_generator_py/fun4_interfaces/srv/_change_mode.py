# generated from rosidl_generator_py/resource/_idl.py.em
# with input from fun4_interfaces:srv/ChangeMode.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ChangeMode_Request(type):
    """Metaclass of message 'ChangeMode_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fun4_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fun4_interfaces.srv.ChangeMode_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__change_mode__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__change_mode__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__change_mode__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__change_mode__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__change_mode__request

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChangeMode_Request(metaclass=Metaclass_ChangeMode_Request):
    """Message class 'ChangeMode_Request'."""

    __slots__ = [
        '_mode',
        '_teleop_mode',
        '_pose',
    ]

    _fields_and_field_types = {
        'mode': 'int64',
        'teleop_mode': 'int64',
        'pose': 'geometry_msgs/Point',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get('mode', int())
        self.teleop_mode = kwargs.get('teleop_mode', int())
        from geometry_msgs.msg import Point
        self.pose = kwargs.get('pose', Point())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.mode != other.mode:
            return False
        if self.teleop_mode != other.teleop_mode:
            return False
        if self.pose != other.pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'mode' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._mode = value

    @builtins.property
    def teleop_mode(self):
        """Message field 'teleop_mode'."""
        return self._teleop_mode

    @teleop_mode.setter
    def teleop_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'teleop_mode' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'teleop_mode' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._teleop_mode = value

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'pose' field must be a sub message of type 'Point'"
        self._pose = value


# Import statements for member types

# Member 'config'
import array  # noqa: E402, I100

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_ChangeMode_Response(type):
    """Metaclass of message 'ChangeMode_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fun4_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fun4_interfaces.srv.ChangeMode_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__change_mode__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__change_mode__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__change_mode__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__change_mode__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__change_mode__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChangeMode_Response(metaclass=Metaclass_ChangeMode_Response):
    """Message class 'ChangeMode_Response'."""

    __slots__ = [
        '_success',
        '_config',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'config': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.config = array.array('d', kwargs.get('config', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.config != other.config:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def config(self):
        """Message field 'config'."""
        return self._config

    @config.setter
    def config(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'config' array.array() must have the type code of 'd'"
            self._config = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'config' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._config = array.array('d', value)


class Metaclass_ChangeMode(type):
    """Metaclass of service 'ChangeMode'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('fun4_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'fun4_interfaces.srv.ChangeMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__change_mode

            from fun4_interfaces.srv import _change_mode
            if _change_mode.Metaclass_ChangeMode_Request._TYPE_SUPPORT is None:
                _change_mode.Metaclass_ChangeMode_Request.__import_type_support__()
            if _change_mode.Metaclass_ChangeMode_Response._TYPE_SUPPORT is None:
                _change_mode.Metaclass_ChangeMode_Response.__import_type_support__()


class ChangeMode(metaclass=Metaclass_ChangeMode):
    from fun4_interfaces.srv._change_mode import ChangeMode_Request as Request
    from fun4_interfaces.srv._change_mode import ChangeMode_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
