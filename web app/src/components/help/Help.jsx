import './help.scss';
import { useEffect, useState } from 'react';
import { onAuthStateChanged } from 'firebase/auth';

import { ThemeProvider } from '@mui/material/styles';
import { auth } from '../../firebase/firebase';
import { Container } from '@mui/material';
import theme from '../../reusable/Theme/Theme';
import Question from '../../reusable/Question/Question';
import faqBgImage from '../../assets/faq.png';

function Help() {
  // eslint-disable-next-line no-unused-vars
  const [isAuth, setIsAuth] = useState(false);

  useEffect(() => {
    onAuthStateChanged(auth, currentUser => {
      if (currentUser) {
        setIsAuth(true);
      }
    });
  }, []);
  return (
    <div className='help'>
      <div>
        <ThemeProvider theme={theme}>
          <div
            className='faq'
            style={{
              backgroundImage: `url(${faqBgImage})`,
              backgroundRepeat: 'no-repeat',
              backgroundSize: 'contain',
            }}
          ></div>

          <Container className='questions-container'>
            <Question
              question='What is it?'
              answer='This device guides you to the exact medicine at appropriate time.Just fill the ergonomically designed compartments of the box with medicines. Set the medicine timings into this microcomputer box from anywhere  using this web App '
            />
            <Question
              question='How does it work?'
              answer='it gives you audio visual Alarm on time and guides you to the exact slot to take medicine.'
            />
            <Question
              question='Do i need to use after setting the alarms?'
              answer='You don’t need the App anymore as long as you stick to the same schedule. Of course you can reprogram the Box any number of times using the App to suit the revised prescription. The Box remembers the schedule even during power failure.'
            />
            <Question
              question='how can i sign up?'
              answer='Contact us to provide u with an email and password'
            />
          </Container>
        </ThemeProvider>
      </div>
    </div>
  );
}
export default Help;
