import { useEffect, useRef } from 'react';
import Typed from 'typed.js';
import './home.scss';
import deviceImg1 from '../../assets/device1.png';
import deviceImg2 from '../../assets/device3.png';

function Home() {
  const typeRef = useRef(null);

  useEffect(() => {
    const typed = new Typed(typeRef.current, {
      strings: [
        'Welcome To Teryaq - Your Partner in Better Health',
        "Don't Miss A Beat - Teryaq Keeps You On Schedule",
        'Simplifying Your Medication Routine - With Teryaq',
      ],
      typeSpeed: 50,
      backSpeed: 50,
      smartBackspace: true,
      loop: true,
      loopCount: Infinity,
    });
    return () => {
      typed.destroy();
    };
  }, []);

  return (
    <main id='home'>
      <div className='main-section'>
        <div>
          <span ref={typeRef}></span>
        </div>
        <p>
          Teryaq is a smart medication box that simplifies your medication
          routine and helps you stay on top of your health. Join the Teryaq
          community today and experience the future of medication management.
        </p>

        <a className='main-section-btn' href='#section1'>
          Read More
        </a>
      </div>

      <div className='section1' id='section1'>
        <div className='section1-info'>
          <h2>Simple Setup, Seamless Experience</h2>
          <p>
            Getting started with Teryaq is easy. Simply load your medication
            into our smart medication box, set your schedule on our website, and
            let Teryaq take care of the rest. Our intuitive interface and
            automated reminders make it easy to stay on track with your
            medication routine, giving you a seamless experience from day one.
          </p>
        </div>

        <img src={deviceImg2} alt='bgImage' />
      </div>

      <div className='section2'>
        <img src={deviceImg1} alt='bgImage' />

        <div className='section2-info'>
          <h2>Your Smart Medication Solution</h2>
          <p>
            Teryaq&apos;s smart technology keeps your medication safe and
            secure. Our airtight compartments prevent pills from populating and
            protect them from heat, moisture, and light. With Teryaq, you can
            trust that your medication stays fresh and potent, helping you
            achieve better health outcomes. Discover how Teryaq can help you
            keep your medication safe today.
          </p>
        </div>
      </div>

      <div className='subscribe-section'>
        <h2>Join Our Community and Get Your Own Medication Box</h2>
        <p>
          Sign up now and take control of your medication with Teryaq. Just
          enter your email address below, and we&apos;ll be in touch to help you
          get started.
        </p>
        <form className='subscribe-email'>
          <input type='email' name='email' id='email' />
          <button id='subscribe-btn'>Subscribe</button>
        </form>
      </div>
    </main>
  );
}
export default Home;
