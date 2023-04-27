#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER my_provider

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./myTp.h"

#if !defined(_TP_H) || \
    defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>
#include <stdio.h>

#include "app.h"

LTTNG_UST_TRACEPOINT_EVENT(
    my_provider,
    simple_event,
    LTTNG_UST_TP_ARGS(
        int, my_integer_arg,
        const char *, my_string_arg
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_string(argv, my_string_arg)
        lttng_ust_field_integer(int, argc, my_integer_arg)
    )
)

LTTNG_UST_TRACEPOINT_ENUM(
    my_provider,
    my_enum,
    LTTNG_UST_TP_ENUM_VALUES(
        lttng_ust_field_enum_value("ZERO", 0)
        lttng_ust_field_enum_value("ONE", 1)
        lttng_ust_field_enum_value("TWO", 2)
        lttng_ust_field_enum_range("A RANGE", 52, 125)
        lttng_ust_field_enum_value("ONE THOUSAND", 1000)
    )
)

LTTNG_UST_TRACEPOINT_EVENT(
    my_provider,
    big_event,
    LTTNG_UST_TP_ARGS(
        int, my_integer_arg,
        const char *, my_string_arg,
        FILE *, stream,
        double, flt_arg,
        int *, array_arg
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer(int, int_field1, my_integer_arg * 2)
        lttng_ust_field_integer_hex(long int, stream_pos,
                                    ftell(stream))
        lttng_ust_field_float(double, float_field, flt_arg)
        lttng_ust_field_string(string_field, my_string_arg)
        lttng_ust_field_array(int, array_field, array_arg, 9)
      )
)

LTTNG_UST_TRACEPOINT_LOGLEVEL(my_provider, big_event,
                              LTTNG_UST_TRACEPOINT_LOGLEVEL_INFO)

LTTNG_UST_TRACEPOINT_EVENT_CLASS(
    my_provider,
    my_tracepoint_class,
    LTTNG_UST_TP_ARGS(
        int, my_integer_arg,
        struct app_struct *, app_struct_arg
    ),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer(int, a, my_integer_arg)
        lttng_ust_field_integer(unsigned long, b, app_struct_arg->b)
        lttng_ust_field_string(c, app_struct_arg->c)
    )
)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    my_provider,
    my_tracepoint_class,
    my_provider,
    event_instance1,
    LTTNG_UST_TP_ARGS(
        int, my_integer_arg,
        struct app_struct *, app_struct_arg
    )
)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    my_provider,
    my_tracepoint_class,
    my_provider,
    event_instance2,
    LTTNG_UST_TP_ARGS(
        int, my_integer_arg,
        struct app_struct *, app_struct_arg
    )
)

LTTNG_UST_TRACEPOINT_LOGLEVEL(my_provider, event_instance2,
                              LTTNG_UST_TRACEPOINT_LOGLEVEL_INFO)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    my_provider,
    my_tracepoint_class,
    my_provider,
    event_instance3,
    LTTNG_UST_TP_ARGS(
        int, my_integer_arg,
        struct app_struct *, app_struct_arg
    )
)

#endif /* _TP_H */

#include <lttng/tracepoint-event.h>
