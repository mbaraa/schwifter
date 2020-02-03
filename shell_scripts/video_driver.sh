#Video Driver Checker & Installer Script.
lspci  -v -s  $(lspci | grep ' VGA ' | cut -d" " -f 1) | grep 'Kernel modules: ' > vga.txt
kk="cat vga.txt"
#vga_card="none"
#AMDGPU
$kk | grep amdgpu || echo "Not amdgpu!"
$kk | grep amdgpu && vga_card="amdgpu"
#$kk | grep amdgpu && emerge -qv xf86-video-amdgpu
#RADEON
$kk | grep radeon || echo "Not radeon!"
$kk | grep radeon && vga_card="ati"
#$kk | grep radeon && emerge -qv xf86-video-ati
#INTEL
$kk | grep intel  || echo "Not intel!"
$kk | grep intel && vga_card="intel"
#VM WARE
$kk | grep vmware || echo "Not vmware!"
$kk | grep vmware && vga_card="vmware"
#VirtualBox
$kk | grep vboxvideo || echo "Not vboxvideo!"
$kk | grep vboxvideo && vga_card="vboxvideo"
#NVIDIA
$kk | grep nvidia || echo "Not nvidia!"
$kk | grep nvidia && vga_card="nouveau"
#Nouveau [NVIDIA]
$kk | grep nouveau || echo "Not nouveau!"
$kk | grep nouveau && vga_card="nouveau"
#Vesa
$kk | grep vesa || echo "Not vesa!"
$kk | grep vesa && vga_card="vesa"
#Dummy
$kk | grep dummy || echo "Not dummy!"
$kk | grep dummy && vga_card="dummy"

printf "Detected $vga_card chip ....\n"

#Installing the package
emerge -qv xf86-video-$vga_card
rm vga.txt
