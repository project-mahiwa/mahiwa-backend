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
run-pico:
	pio run -t upload -e pico
	@make monitor -e pico
run-atom:
	pio run -t upload -e m5stack-atom
	@make monitor -e m5stack-atom
run-atoms3:
	pio run -t upload -e m5stack-atoms3
	@make monitor -e m5stack-atoms3
run-core2:
	pio run -t upload -e m5stack-core2
	@make monitor -e m5stack-core2
run-c3:
	pio run -t upload -e seeed_xiao_esp32c3
	@make monitor -e seeed_xiao_esp32c3

debug-atom:
	pio debug -e m5stack-atom
