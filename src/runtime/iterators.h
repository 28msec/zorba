#ifndef XQP_ITERATORS_H
#define XQP_ITERATORS_H

namespace xqp {
	
	template <class IterType>
	class UnaryBaseIterator : public Batcher<IterType>
	{
		protected:
			Iterator_t iter;
		
		public:
			UnaryBaseIterator
				( const yy::location& loc, Iterator_t& arg);
			virtual ~UnaryBaseIterator();

			void resetImpl(IteratorTreeStateBlock& stateBlock);
			void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			
			virtual int32_t getStateSize();
			virtual int32_t getStateSizeOfSubtree();
			virtual void setOffset(int32_t& offset);
	}; /* class UnaryBaseIterator */
	
	template <class IterType>
	class BinaryBaseIterator : public Batcher<IterType>
	{
		protected:
			Iterator_t iter0;
			Iterator_t iter1;
			
		public:
			BinaryBaseIterator
				( const yy::location& loc, Iterator_t& arg0, Iterator_t& arg1 );
			virtual ~BinaryBaseIterator();

			void resetImpl(IteratorTreeStateBlock& stateBlock);
			void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			
			virtual int32_t getStateSize();
			virtual int32_t getStateSizeOfSubtree();
			virtual void setOffset(int32_t& offset);
	}; /* class BinaryBaseIterator */
	
	template <class IterType>
	class NaryBaseIterator : public Batcher<IterType>
	{
		protected:
			std::vector<Iterator_t> iters;
			
		public:
			NaryBaseIterator
				( const yy::location loc, Iterator_t arg0, Iterator_t arg1 );
			virtual ~NaryBaseIterator();

			void resetImpl(IteratorTreeStateBlock& stateBlock);
			void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			
			virtual int32_t getStateSize();
			virtual int32_t getStateSizeOfSubtree();
			virtual void setOffset(int32_t& offset);
	}; /* class BinaryBaseIterator */
} /* namespace xqp */

#endif	/* XQP_ITERATORS_H */
