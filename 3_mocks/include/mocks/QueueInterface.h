class QueueInterface {
public:
  virtual ~QueueInterface() {};
  virtual void enqueue(int data) = 0;
  virtual int dequeue() = 0;
};
