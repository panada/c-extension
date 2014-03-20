
extern zend_class_entry *panada_test_ce;

ZEPHIR_INIT_CLASS(Panada_Test);

PHP_METHOD(Panada_Test, __construct);
PHP_METHOD(Panada_Test, get);
PHP_METHOD(Panada_Test, get2);

ZEPHIR_INIT_FUNCS(panada_test_method_entry) {
	PHP_ME(Panada_Test, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Panada_Test, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Panada_Test, get2, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
