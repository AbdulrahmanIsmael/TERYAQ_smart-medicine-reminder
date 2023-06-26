import { useState, useEffect } from 'react';
import './emergency.scss';
import { database } from '../../firebase/firebase';
import { ref, set, onValue } from 'firebase/database';
import CloseIcon from '@mui/icons-material/Close';

const initialInputs = {
  name: '',
  phone: '',
};

const initialPlaceholders = {
  name: 'Emergency Contact Name...',
  phone: 'Emergency Contact Phone...',
};

function Emergency() {
  const [inputs, setInputs] = useState(initialInputs);
  const [placeholders, setPlaceholders] = useState(initialPlaceholders);
  const [showForm, setShowForm] = useState(false);
  const [emerDetails, setEmerDetails] = useState({
    name: '-',
    phone: '-',
  });

  useEffect(() => {
    const phoneRef = ref(database, 'phone');
    const nameRef = ref(database, 'name');

    onValue(phoneRef, snapshot => {
      const phone = snapshot.val();

      setEmerDetails(prevDetails => {
        return {
          ...prevDetails,
          phone: phone,
        };
      });
    });

    onValue(nameRef, snapshot => {
      const phone = snapshot.val();

      setEmerDetails(prevDetails => {
        return {
          ...prevDetails,
          name: phone,
        };
      });
    });
  }, [inputs]);

  const sendToFirebase = (phone, name) => {
    const phoneRef = ref(database, 'phone');
    const nameRef = ref(database, 'name');

    set(nameRef, name);
    set(phoneRef, Number(phone))
      .then(() => console.log('Process Is Done'))
      .catch(error => console.log(error));
  };

  const sendPhoneToFirebase = e => {
    e.preventDefault();

    if (inputs.name && inputs.phone) {
      sendToFirebase(inputs.phone, inputs.name);
      setShowForm(false);
    } else {
      if (!inputs.name) {
        setPlaceholders(draftPlaceholders => {
          return {
            ...draftPlaceholders,
            name: "Please Don't leave that empty!",
          };
        });
      }

      if (!inputs.phone) {
        setPlaceholders(draftPlaceholders => {
          return {
            ...draftPlaceholders,
            phone: "Please Don't leave that empty!",
          };
        });
      }
    }
  };

  const closeFormWindow = () => {
    setShowForm(false);
    setPlaceholders(initialPlaceholders);
  };

  return (
    <div className='emergency'>
      <h2>Emergency Contact Information</h2>
      <div className='emergency-ins'>
        <div className='emergency-move'>
          <p>
            Please fill out the following information so that we can contact
            someone in case of an emergency.
          </p>
          <p>
            This information will only be used for emergency purposes and will
            not be shared with anyone else.
          </p>
        </div>
      </div>
      <button className='emergency-btn' onClick={() => setShowForm(true)}>
        Insert
      </button>

      <div
        className={
          showForm ? 'emergency-form' : 'emergency-form emergency-form--hide'
        }
      >
        <form>
          <legend>
            Emergency Contact
            <CloseIcon
              className='emergency-form-close'
              sx={{
                backgroundColor: '#ff0000',
                color: '#fff',
                borderRadius: '0.6em',
              }}
              onClick={closeFormWindow}
            />
          </legend>
          <div className='emergency-form-inputs'>
            <div>
              <label htmlFor='name'>Emergency Name</label>
              <input
                type='text'
                name='name'
                id='name'
                placeholder={placeholders.name}
                value={inputs.name}
                onChange={e => setInputs({ ...inputs, name: e.target.value })}
              />
            </div>
            <div>
              <label htmlFor='phone'>Emergency Phone</label>
              <input
                type='tel'
                name='phone'
                id='phone'
                placeholder={placeholders.phone}
                value={inputs.phone}
                onChange={e => setInputs({ ...inputs, phone: e.target.value })}
              />
            </div>
          </div>
          <button className='emergency-form-set' onClick={sendPhoneToFirebase}>
            Set Emergency Contact
          </button>
        </form>
      </div>

      <div className='emergency-details'>
        <h2>Emergency Details</h2>

        <div className='personal-details'>
          <div className='emergency-name'>
            <h3>Name:</h3>
            <p>{emerDetails.name}</p>
          </div>
          <div className='emergency-phone'>
            <h3>Phone:</h3>
            <p>{emerDetails.phone}</p>
          </div>
        </div>
      </div>

      <div className={showForm ? 'overlay' : 'overlay overlay--hide'}></div>
    </div>
  );
}

export default Emergency;
