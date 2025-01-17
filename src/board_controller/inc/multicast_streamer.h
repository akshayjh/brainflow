#pragma once

#include <thread>

#include "data_buffer.h"
#include "multicast_server.h"
#include "streamer.h"


class MultiCastStreamer : public Streamer
{

public:
    static int get_packages_in_chunk ();

    MultiCastStreamer (const char *ip, int port, int data_len);
    ~MultiCastStreamer ();

    int init_streamer ();
    void stream_data (double *data);

private:
    char ip[128];
    int port;
    MultiCastServer *server;
    DataBuffer *db;
    volatile bool is_streaming;
    std::thread streaming_thread;

    void thread_worker ();
};
