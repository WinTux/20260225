#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/timekeeping.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pepe Perales");
MODULE_DESCRIPTION("Monitor de conexiones SSH entrantes");

static struct nf_hook_ops nfho;
static unsigned int ssh_monitor_hook(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) {
	struct iphdr *iph;
	struct tcphdr *tcph;
	struct timespec64 ts;
	if(!skb)
		return NF_ACCEPT;
	iph = ip_hdr(skb);
	if(!iph)
		return NF_ACCEPT;
	if(iph->protocol == IPPROTO_TCP) {
		tcph = tcp_hdr(skb);
		if(ntohs(tcph->dest) == 22 && tcph->syn) {
			ktime_get_real_ts64(&ts);
			printk(KERN_INFO "[Monitor SSH] : Conexión entrante - IP: %pI4, Puerto origen: %u, Timestamp: %lld\n", &iph->saddr, ntohs(tcph->source),(s64)ts.tv_sec);
		}
	}
	return NF_ACCEPT;
}

static int __init ssh_monitor_init(void) {
	nfho.hook = ssh_monitor_hook;
	nfho.hooknum = NF_INET_PRE_ROUTING;
	nfho.pf = PF_INET;
	nfho.priority = NF_IP_PRI_FIRST;
	nf_register_net_hook(&init_net, &nfho);
	printk(KERN_INFO "[Monitor SSH] : Módulo SSH cargado.\n");
	return 0;
}

static void __exit ssh_monitor_exit(void) {
	nf_unregister_net_hook(&init_net, &nfho);
	printk(KERN_INFO "[Monitor SSH] : Módulo SSH descargado.\n");
}

module_init(ssh_monitor_init);
module_exit(ssh_monitor_exit);
