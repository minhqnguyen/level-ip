#include "syshead.h"
#include "sock.h"
#include "socket.h"

struct sock *sk_alloc(struct net_ops *ops, int protocol)
{
    struct sock *sk;

    sk = ops->alloc_sock(protocol);

    sk->ops = ops;

    return sk;
}

void sock_init_data(struct socket *sock, struct sock *sk)
{
    sock->sk = sk;
    sk->sock = sock;

    wait_init(&sk->recv_wait);
    skb_queue_init(&sk->receive_queue);
}
