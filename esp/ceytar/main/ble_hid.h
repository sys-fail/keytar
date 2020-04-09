
void ble_hid_setup(void);

typedef struct {
  uint8_t mod;
  uint8_t key;
} keymap_t;
void ble_hid_send(keymap_t);

