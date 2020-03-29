#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

COMPONENT_SRCDIRS += data_port
COMPONENT_ADD_INCLUDEDIRS += data_port


COMPONENT_SRCDIRS += lt768ui_port
COMPONENT_ADD_INCLUDEDIRS += lt768ui_port

COMPONENT_SRCDIRS += business
COMPONENT_ADD_INCLUDEDIRS += business

COMPONENT_SRCDIRS += business/service
COMPONENT_ADD_INCLUDEDIRS += business/service

COMPONENT_SRCDIRS += mcb_port
COMPONENT_ADD_INCLUDEDIRS += mcb_port


