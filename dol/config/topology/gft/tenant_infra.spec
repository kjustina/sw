# Configuration Template.
meta:
    id: TENANT_INFRA_GFT

type    : infra
overlay : vlan

segments:
    - spec  : ref://store/specs/id=SEGMENT_INFRA_GFT
      count : 1

tunnels:
    - spec  : ref://store/specs/id=TUNNEL_VXLAN

security_profile: None

sessions:
    unidest:
        ipv4:
            - ref://store/specs/id=SESSION_UDP_SERVICES_GFT
        ipv6: None
        mac: None

lif: ref://store/specs/id=LIF_ETH
