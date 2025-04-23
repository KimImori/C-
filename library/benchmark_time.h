#ifndef BENCHMARK_TIME_H
#define BENCHMARK_TIME_H

#include <time.h>
#include <assert.h>


struct timespec diff_timespec(const struct timespec* start, const struct timespec* end)
{
    assert(start);
    assert(end);
    struct timespec diff = {
      .tv_sec = end->tv_sec - start->tv_sec,
      .tv_nsec = end->tv_nsec - start->tv_nsec
    };
    if (diff.tv_nsec < 0)
    {
      diff.tv_sec--;
      diff.tv_nsec += 1000000000;
    }
    return diff;
}

double timespec_as_seconds(const struct timespec* ts)
{
  assert(ts);
  return (double)ts->tv_sec + 1.0e-9*ts->tv_nsec;
}

#endif