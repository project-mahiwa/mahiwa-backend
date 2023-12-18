check:
	pio check
test:
	pio test
update:
	pio update
	pio upgrade
list:
	pio device list
debug:
	pio debug
monitor:
	pio device monitor -b 115200
r-pico-w:
	pio run -t upload -e pico
	@make monitor
# M5 ATOM Matrixはwasm3が動かない(PSRAMが無い)が，壊れの検証用にあえて残しておく
r-atom-m:
	pio run -t upload -e m5stack-atom
	@make monitor
r-atom-s3:
	pio run -t upload -e m5stack-atoms3
	@make monitor
r-core2:
	pio run -t upload -e m5stack-core2
	@make monitor
r-c3:
	pio run -t upload -e seeed_xiao_esp32c3
	@make monitor

debug-atom:
	pio debug -e m5stack-atom

coremark:
	cp /opt/usuyuki/mahiwa_space/wasm-coremark/coremark-minimal.wasm /opt/usuyuki/.cache/mahiwa/user.wasm
	wasm2wat /opt/usuyuki/.cache/mahiwa/user.wasm -o /opt/usuyuki/.cache/mahiwa/user.wat
	(cd /opt/usuyuki/.cache/mahiwa && xxd -i user.wasm > user.h)
	cp /opt/usuyuki/.cache/mahiwa/user.h /opt/usuyuki/mahiwa_space/mahiwa-backend/src/wasm/user.h

coremarkh:
	cp /home/usuyuki/mahiwa_space/wasm-coremark/coremark-minimal.wasm /home/usuyuki/.cache/mahiwa/user.wasm
	wasm2wat /home/usuyuki/.cache/mahiwa/user.wasm -o /home/usuyuki/.cache/mahiwa/user.wat
	(cd /home/usuyuki/.cache/mahiwa && xxd -i user.wasm > user.h)
	cp /home/usuyuki/.cache/mahiwa/user.h /home/usuyuki/mahiwa_space/mahiwa-backend/src/wasm/user.h
