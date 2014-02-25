
extern zend_class_entry *panada_config_ce;

ZEPHIR_INIT_CLASS(Panada_Config);

PHP_METHOD(Panada_Config, main);

ZEPHIR_INIT_FUNCS(panada_config_method_entry) {
	PHP_ME(Panada_Config, main, NULL, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
