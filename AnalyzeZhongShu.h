#ifndef ANALYZEZHONGSHU_H
#define ANALYZEZHONGSHU_H




template <class XianDuanClass>
class AnalyzeZhongShu_Template
{
public:
	typedef typename XianDuanClass::baseItemType_Container::iterator baseItemIterator;
	typedef typename XianDuanClass::ContainerType::iterator ItemIterator;
	typedef typename XianDuanClass::baseItemType baseItemType;
	typedef typename XianDuanClass::ContainerType ContainerType;
	typedef typename XianDuanClass::baseItemType_Container baseItemType_Container;


	static void handleTurningPoint(baseItemType *start, baseItemType *end)
	{
/*
  �������ϵ��߶�˵�� TurningPoint(TP)��ָ �����ĵ㣺 TP1��TP2

               TP2       /
                /\      /
     TP1       /  \    end
      /\      /    \  /
     /  \    /      \/
TP1_1  TP1_2/
   /      \/
  /
 
 �������µ��߶Σ�TurningPoint��ָ �����ĵ㣺TP1��TP2
  \
   \        /\
 TP1_1  TP1_2 \
	 \    /    \        /\
	  \  /      \      /  \
	   \/        \    /    \
      TP1         \  /      end
                   \/        \
                  TP2         \
                               \
*/
		baseItemType *TP1_1 = start;
		baseItemType *TP1_2 = start + 1;
		while (TP1_1 < end)
		{
			//if (TP1_1->
		}

	}

	static void handleJuxtaposition(baseItemType *start, baseItemType *end)
	{
/*
  �������ϵ��߶�˵�� Juxtaposition(JP)��ָ ���������ڣ������غ�����ģ��߶�: JP0/JP1/JP2/JP3 ��  JP2/JP3/JP4/JP5

                           /\
                          /  \      /
                         /   JP5   /
                /\     JP4     \  /
               /  \    /        \/
      /\     JP2  JP3 /
     /  \    /      \/
   JP0  JP1 /
   /      \/
  /

  �������µ��߶�˵�� Juxtaposition��ָ ���������ڣ������غ�����ģ��߶�: JP0/JP1/JP2/JP3 ��  JP2/JP3/JP4/JP5

  \
   \      /\
   JP0  JP1 \          
	 \  /    \        /\
      \/    JP2     JP3 \
               \    /    \          /
                \  /      \        /
                 \/       JP4    JP5
                            \    /
                             \  /
                              \/

  �������е��߶�(��������߶η��������ϵ�)��Juxtaposition��ָ�� JP0/JP1/JP2/JP3/JP4/JP5
   
                                 /\
                                /  \
                               /    \
                /\            /      \
     /\        /  \          /        \
    /  \      /    \        /          \
  JP0  JP1  JP2    JP3    JP4          JP5
  /      \  /        \    /              \
          \/          \  /                \
                       \/

 �������е��߶�(��������߶η��������µ�)��Juxtaposition��ָ�� JP0/JP1/JP2/JP3
   
                                 /\
                                /  \
                               /    \
                /\            /      \
     /\        /  \          /        \
    /  \      /    \        /          \
   /  JP0   JP1    JP2    JP3           \
  /      \  /        \    /              \
          \/          \  /                \
                       \/

*/

	}

	static void doWork() 
	{
		if (XianDuanClass::container == NULL)  return;

		ItemIterator curr = XianDuanClass::container->begin();
		ItemIterator end = XianDuanClass::container->end();
		baseItemType* veryEnd = &(*(XianDuanClass::baseItems->end() - 1));

		while (curr < end)
		{
			baseItemType *first = (*curr).getStart();
			baseItemType *last = (*curr).getEnd();

			handleTurningPoint(first, last);
			handleJuxtaposition(first, last);

			curr++;
		}
		
		// baseItem�����У����ܻ���һЩʣ�����Ŀ��û�й����һ������߶Σ���Ȼ��Ҫ�����������������ࡣ ���еķ�����Ҳ���ǣ�����һ����ʱ�ĸ����߶���������Щʣ������߶Σ�
		baseItemType *remaining = (*(end-1)).getEnd() + 1;
		if (remaining < veryEnd)
		{
			// XianDuanClass temp = new XianDuanClass(baseItemIterator(remaining), baseItemIterator(veryEnd));
			handleTurningPoint(remaining, veryEnd);
			handleJuxtaposition(remaining, veryEnd);
		}
	}
};


template <class XianDuanClass>
void AnalyzeZhongShu_PostOrder()
{
	typedef typename XianDuanClass::baseItemType baseItemType;

	AnalyzeZhongShu_PostOrder<baseItemType>();
	AnalyzeZhongShu_Template<XianDuanClass>::doWork();
}


template <>
void AnalyzeZhongShu_PostOrder<Class_XianDuan<1>>()
{
}

#endif