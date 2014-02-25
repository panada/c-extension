
extern zend_class_entry *panada_gear_ce;

ZEPHIR_INIT_CLASS(Panada_Gear);

PHP_METHOD(Panada_Gear, __construct);
PHP_METHOD(Panada_Gear, ask);

ZEPHIR_INIT_FUNCS(panada_gear_method_entry) {
	PHP_ME(Panada_Gear, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Panada_Gear, ask, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
