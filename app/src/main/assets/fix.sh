#!/system/bin/sh
su -c iptables -F
iptables -F
su -c iptables --flush
iptables --flush
iptables -F
iptables -X
ip6tables --flush
ip6tables -F
su -c iptables -F
su -c iptables -X
su -c ip6tables --flush
su -c ip6tables -F
echo "8192" > /proc/sys/fs/inotify/max_user_instances;
echo "8192" > /proc/sys/fs/inotify/max_user_watches;
echo "8192" > /proc/sys/fs/inotify/max_queued_events;
echo "starting"
if [ $(pidof com.tencent.ig) ]; then
awk '/^com.tencent.ig/ {print $2}' /data/system/packages.list > /data/media/0/uidinf
UID=$(cat /data/media/0/uidinf)
iptables -A OUTPUT -m owner --uid-owner $UID -p tcp -j DROP &> /dev/null

elif [ $(pidof com.pubg.krmobile) ]; then
awk '/^com.pubg.krmobile/ {print $2}' /data/system/packages.list > /data/media/0/uidinf
UID=$(cat /data/media/0/uidinf)
iptables -A OUTPUT -m owner --uid-owner $UID -p tcp -j DROP &> /dev/null

elif [ $(pidof com.vng.pubgmobile) ]; then
awk '/^com.vng.pubgmobile/ {print $2}' /data/system/packages.list > /data/media/0/uidinf
UID=$(cat /data/media/0/uidinf)
iptables -A OUTPUT -m owner --uid-owner $UID -p tcp -j DROP &> /dev/null

elif [ $(pidof com.pubg.imobile) ]; then
awk '/^com.pubg.imobile/ {print $2}' /data/system/packages.list > /data/media/0/uidinf
UID=$(cat /data/media/0/uidinf)
iptables -A OUTPUT -m owner --uid-owner $UID -p tcp -j DROP &> /dev/null
else
echo "No Process Running"
fi
iptables -I INPUT -p tcp --dport 80 -j DROP
iptables -I INPUT -p tcp --dport 8080 -j DROP
iptables -I INPUT -p tcp --dport 18081 -j DROP
iptables -I INPUT -p tcp --dport 3013 -j DROP
iptables -I INPUT -p tcp --dport 1112 -j DROP
iptables -I INPUT -p tcp --dport 11443 -j DROP
iptables -I INPUT -p tcp --dport 17500 -j DROP
iptables -I OUTPUT -p tcp --dport 17500 -j DROP
iptables -I OUTPUT -p tcp --dport 80 -j DROP
iptables -I OUTPUT -p tcp --dport 8080 -j DROP
iptables -I OUTPUT -p tcp --dport 18081 -j DROP
iptables -I OUTPUT -p tcp --dport 3013 -j DROP
iptables -I OUTPUT -p tcp --dport 1112 -j DROP
iptables -I OUTPUT -p tcp --dport 11443 -j DROP
iptables -I OUTPUT -p udp --dport 81 -j DROP
iptables -I OUTPUT -p udp --dport 8011 -j DROP
iptables -I OUTPUT -p udp --dport 111 -j DROP
iptables -I OUTPUT -p udp --dport 11038 -j DROP
iptables -I OUTPUT -p udp --dport 8011 -j DROP
iptables -I OUTPUT -p udp --dport 20001 -j DROP
iptables -I INPUT -p tcp --dport 80 -j REJECT
iptables -I INPUT -p tcp --dport 8080 -j REJECT
iptables -I INPUT -p tcp --dport 8085 -j REJECT
iptables -I INPUT -p tcp --dport 8086 -j REJECT
iptables -I INPUT -p tcp --dport 8088 -j REJECT
iptables -I INPUT -p tcp --dport 18081 -j REJECT
iptables -I INPUT -p tcp --dport 3013 -j REJECT
iptables -I INPUT -p tcp --dport 1112 -j REJECT
iptables -I INPUT -p tcp --dport 11443 -j REJECT
iptables -I INPUT -p tcp --dport 17500 -j REJECT
iptables -I OUTPUT -p tcp --dport 17500 -j REJECT
iptables -I OUTPUT -p tcp --dport 80 -j REJECT
iptables -I OUTPUT -p tcp --dport 8080 -j REJECT
iptables -I OUTPUT -p tcp --dport 8085 -j REJECT
iptables -I OUTPUT -p tcp --dport 8086 -j REJECT
iptables -I OUTPUT -p tcp --dport 8088 -j REJECT
iptables -I OUTPUT -p tcp --dport 18081 -j REJECT
iptables -I OUTPUT -p tcp --dport 3013 -j REJECT
iptables -I OUTPUT -p tcp --dport 1112 -j REJECT
iptables -I OUTPUT -p tcp --dport 11443 -j REJECT