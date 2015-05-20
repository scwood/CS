import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by spencer on 5/18/15.
 */
public class HelloWorldTest {

  private HelloWorld myClass = null;

  @Before
  public void setUp() throws Exception {
    myClass = new HelloWorld();
  }

  @Test
  public void testSayHello() throws Exception {
    assertEquals("hello", myClass.sayHello());
  }

  @Test
  public void testSayOne() throws Exception {
    assertEquals(1, myClass.sayOne());
  }
}