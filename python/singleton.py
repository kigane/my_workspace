class singleton():
    __instance = None

    def __new__(cls):
        """
            在一个对象实例化的时候所调用的第一个方法，在调用__init__初始化前，先调用__new__。
            * __new__至少要有一个参数cls，代表要实例化的类，此参数在实例化时由 Python 解释器自动提供，后面的参数直接传递给__init__。
            * __new__对当前类进行了实例化，并将实例返回，传给__init__的self。但是，执行了__new__，并不一定会进入__init__，只有__new__返回了，当前类cls的实例，当前类的__init__才会进入。
        """
        if cls.__instance is None:
            cls.__instance = object.__new__(cls)  # 当前类cls的实例
            return cls.__instance  
        else:
            return cls.__instance
