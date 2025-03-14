# cyclonedds_unreal5
Unreal 5.5 cyclonedds plugin, communicate with i.e ros2 subs outside unreal.

Add plugin to projects module dependencies. use by #include <dds/dds.h>

Built with latest cyclonedds 0.11.0 and topic discovery on which enables x-types and enables discovery for i.e python-cyclonedds.

/* Whether or not support for type library is included */
#define DDS_HAS_TYPELIB 1

/* Whether or not support for type discovery is included */
#define DDS_HAS_TYPE_DISCOVERY 1

/* Whether or not support for topic discovery is included */
#define DDS_HAS_TOPIC_DISCOVERY 1
